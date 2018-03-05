#include <stdio.h>
#include "calc5_6.h"

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push5_6(double value) {
	if (sp < MAXVAL) {
		val[sp++] = value;
	}
	else {
		printf("Error: stack is full");
	}
}

double pop5_6() {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("Error: Stack is empty");
		return 0.0;
	}
}

