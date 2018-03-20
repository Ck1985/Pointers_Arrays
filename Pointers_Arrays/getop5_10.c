#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc5_10.h"

#define OPERAND 1

int getop5_10(char s[], int argc, char *argv[]) {
	static int indexPointer = 1;
	int i;

	if (indexPointer < argc) {
		i = 0;
		char character;
		while ((character = *(argv[indexPointer]++)) != '\0') {
			if (!isdigit(character) && character != '.') {
				indexPointer++;
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
	else if (indexPointer == argc) {
		indexPointer++;
		return 0;
	}
	else {
		return -1;
	}
}