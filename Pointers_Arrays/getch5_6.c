#include <stdio.h>

#define BUFFSIZE 100

static char buf[BUFFSIZE];
static int bufp = 0;

int getch5_6() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch5_6(int c) {
	if (bufp >= BUFFSIZE) {
		printf("ungetch: Too many character");
	}
	else {
		buf[bufp++] = c;
	}
}