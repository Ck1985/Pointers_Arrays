#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc5_10.h"

#define OPERAND 1

int getop5_10(char s[], int argc, char *argv[]) {
	static int indexPointer = 1;
	int index = 1, i;

	if (indexPointer < argc) {
		i = 0;
		char character;
		while ((character = *(argv[index]++)) != '\0') {
			if (!isdigit(character) && character != '.') {
				return character;
			}
			if (isdigit(character)) {
				s[i++] = character;
			}
		}
		s[i] = '\0';
		indexPointer++;
		return OPERAND;
	}
	else {
		return NULL;
	}
}