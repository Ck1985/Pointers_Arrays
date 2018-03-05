#include <stdio.h>

#define BUFFSIZE5_1 100

static char buffer[BUFFSIZE5_1];
static int buffPos = 0;

static int getch5_1() {
	return (buffPos <= BUFFSIZE5_1 && buffPos > 0) ? buffer[--buffPos] : getchar();
}

static void ungetch5_1(int c) {
	if (buffPos > BUFFSIZE5_1) {
		printf("Error! Too many character");
	}
	else {
		buffer[buffPos++] = c;
	}
}