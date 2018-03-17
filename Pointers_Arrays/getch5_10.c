#include <stdio.h>
#include "calc5_10.h"

#define BUFFSIZE 1000

static int buffer[BUFFSIZE];
static int buffPos = 0;
int index = 1;

int getch5_10(int argc, char *argv[]) {
	if (buffPos > 0) {
		return buffer[--buffPos];
	}
	else {
		char character = *argv[index++];
		return character;
	}
}

void ungetch5_10(int c) {
	if (buffPos >= BUFFSIZE) {
		printf("Error! buffer is full");
	}
	else {
		buffer[buffPos++] = c;
	}
}