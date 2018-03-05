#include <stdio.h>

#define BUFFSIZE5_2 100

static char buffer[BUFFSIZE5_2];
static int bufPos = 0;

static int getch5_2() {
	return (bufPos > 0 && bufPos <= BUFFSIZE5_2) ? buffer[--bufPos] : getchar();
}

static void ungetch5_2(int c) {
	if (bufPos < BUFFSIZE5_2) {
		buffer[bufPos++] = c;
	}
	else {
		printf("Error! Too many character in buffer");
	}
}