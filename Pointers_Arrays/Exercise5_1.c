/* ----------- Fix source code to push bach character ---------------- */
#include <stdio.h>

#include "getch5_1.c"

int getch5_1(void);
void ungetch5_1(int c);

static int getint5_1(int *pn) {
	int c, sign;

	while (isspace(c = getch5_1()))
		;
	if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
		ungetch5_1(c);
		return 0;
	}
	sign = ((c == '-') ? -1 : 1);
	if (c == '+' || c == '-') {
		c = getch();
	}
	for (*pn = 0; isdigit(c); c = getch5_1()) {
		*pn = 10 * (*pn) + (c - '0');
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch5_1(c);
	}
	return c;
}