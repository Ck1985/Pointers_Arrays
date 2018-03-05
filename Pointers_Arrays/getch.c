#include <stdio.h>

#define BUFFSIZE 100

static char buf[BUFFSIZE];
static int bufp = 0;

static int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

static void ungetch(int c) {
	if (bufp >= BUFFSIZE) {
		printf("Error! Too many character");
	}
	else {
		buf[bufp++] = c;
	}
	return 0;
}