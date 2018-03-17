/* Program expr: evalutes reverse polish notation from Command lines */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc5_10.h"

int main(int argc, char *argv[]) {
	double result = 0;
	int c;
	int op1, op2;
	char s[MAXSIZE];
	while ((c = getop5_10(s, argc, argv)) != EOF) {
		switch (c) {
		case 0:
			push5_10(atof(s));
			break;
		case '+': 
			op2 = pop5_10();
			op1 = pop5_10();
			result = op2 + op1;
			push5_10(result);
			break;
		case '-':
			op2 = pop5_10();
			op1 = pop5_10();
			result = op1 - op2;
			push5_10(result);
			break;
		case '*':
			op2 = pop5_10();
			op1 = pop5_10();
			result = op1 * op2;
			push5_10(result);
			break;
		case '/':
			op2 = pop5_10();
			if (op2 == 0) {
				printf("Error! division zero");
			}
			else {
				op1 = pop5_10();
				result = op1 / op2;
				push5_10(result);
			}
		break;
		case '\n':
			printf("Result Reverse Polish Notation is: %d\n", pop5_10());
		default:
			printf("Error Unknown operator !!!");
			break;
		}
	}

	return result;

	return 0;
}