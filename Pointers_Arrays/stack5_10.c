#include "calc5_10.h"

#define MAXSIZE 100

static int stack[MAXSIZE];
static int stackPos = 0;

void push5_10(int c) {
	if (stackPos < MAXSIZE) {
		stack[stackPos++] = c;
	}
	else {
		printf("Error: Stack is full");
	}
}

int pop5_10() {
	if (stackPos > 0) {
		return stack[--stackPos];
	}
	else {
		printf("Error Stack is Empty");
	}
}