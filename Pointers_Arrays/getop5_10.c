#include <stdio.h>
#include "calc5_10.h"

#define OPERAND 0

int getop5_10(char s[], int argc, char *argv[]) {
	int i = 0, c;

	while ((s[0] = c = getch5_10(argc, argv)) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;
	}
	while (isdigit(c)) {
		s[i++] = c;
		c = getch5_10(argc, argv);
	}
	if (c == '.') {
		while (isdigit(c)) {
			s[i++] = c;
			c = getch5_10(argc, argv);
		}
	}
	if (c != EOF) {
		ungetch5_10(c);
	}
	s[i] = '\0';

	return OPERAND;
}