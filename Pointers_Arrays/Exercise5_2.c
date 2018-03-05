#include <ctype.h>

#include "getch5_2.c"

int getch5_2(void);
void ungetch5_2(int c);

static float getFloat(float *pn) {
	int c;
	float fraction = 1, sign;

	while (isspace(c = getch5_2()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch5_2(c);
		*pn = 0;
		return 0;
	}
	sign = ((c == '-') ? -1 : 1);
	if (c == '+' || c == '-') {
		c = getch5_2();
	}
	if (isdigit(c)) {
		for (*pn = 0; isdigit(c); c = getch5_2()) {
			*pn = 10 * (*pn) + (c - '0');
		}
	}
	if (c == '.') {
		while (isdigit(c = getch5_2())) {
			fraction = fraction / 10;
			*pn = *pn + (c - '0') * fraction;
		}
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch5_2(c);
	}
	return c;
}