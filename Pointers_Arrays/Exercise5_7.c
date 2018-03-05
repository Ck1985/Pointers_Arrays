#include <stdio.h>
#include <string.h>
#include "sorting_line.h"

#define MAXLINES 5000
#define MAXLEN 1000

static char *allocp5_7;
char *alloc5_7(int n, char allocbuf[], int allocsize);

int readlines5_7(char *linesptr[], int maxlen, char allocbuf[], int allocsize) {
	int nlines = 0, len;
	char *linep, line[MAXLEN];
	allocp5_7 = allocbuf;

	while ((len = getline(line, MAXLEN)) > 0) {
		if ((nlines >= MAXLINES) || ((linep = alloc5_7(len, allocbuf, allocsize)) == NULL)) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy(linep, line);
			linesptr[nlines++] = linep;
		}
	}

	return nlines;
}

char *alloc5_7(int n, char allocbuf[], int allocsize) {
	if (allocbuf + allocsize - allocp5_7 >= n) {
		allocp5_7 += n;
		return allocp5_7 - n;
	}
	else {
		return 0;
	}
}