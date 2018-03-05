#include <stdio.h>
#include <ctype.h>

#include "calc5_6.h"

//int getch5_6(void);
//void ungetch5_6(int);

int getop5_6(char *ps) {
	int c;
	char *initps;
	initps = ps;

	while ((*ps = c = getch5_6()) == ' ' || c == '\t')
		;
	ps++;
	ps = '\0';
	if (!isdigit(c) && c != '.') {
		return c;
	}
	ps = initps;
	if (isdigit(c)) {
		while (isdigit(*(++ps) = c = getch5_6()))
			;
	}
	if (c == '.') {
		while (isdigit(*(++ps) = c = getch5_6()))
			;
	}
	*ps = '\0';
	if (c != EOF) {
		ungetch5_6(c);
	}

	return NUMBER;
}