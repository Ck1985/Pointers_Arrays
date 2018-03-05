/* function getint: get next integer form input into pointer *pn */
#include <ctype.h>

#include "getch.c"

int getch(void);
void ungetch(int);

static int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch())) {
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = ((c == '-') ? -1 : 1);
	if (c == '+' || c == '-') {
		c = getch();
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * (*pn) + (c - '0');
	}
	//*pn = sign * (*pn);
	// Or
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}