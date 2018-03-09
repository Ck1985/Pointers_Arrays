/* This file contains 3 function: readlines, writelines and sortlines by using quicksort */
#include <stdio.h>
#include <string.h>
#include "sorting_line.h"

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *linesptr[], int maxlen) {
	int nlines = 0, len;
	char *p, line[MAXLEN];

	while ((len = getline(line, MAXLEN)) > 0) {
		if ((nlines >= MAXLINES) || ((p = myalloc(len)) == NULL)) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			linesptr[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char *linesptr[], int nlines) {
	int i;

	for (i = 0; i < nlines; i++) {
		printf("%s\n", linesptr[i]);
	}
}

int getline(char s[], int limit) {
	int c, i;

	for (i = 0, i < limit - 1; ((c = getchar()) != EOF) && (c != '\n'); i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}

int getline2(char *line, int limit) {
	int c, i;

	for (i = 0, i < limit - 1; ((c = getchar()) != EOF) && (c != '\n'); i++) {
		*line++ = c;
	}
	if (c == '\n') {
		*line++ = c;
		i++;
		//line++;
	}
	*line = '\0';

	return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *myalloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else {
		return 0;
	}
}

void quicksort(char *linep[], int low, int high) {
	int pivotIndex, firstOnIndex = -1, countFirst = 1, offIndex, lastOffindex = -1;
	pivotIndex = low - 1;

	if (low >= high) {
		return 0;
	}
	for (int i = low; i <= high; i++) {
		if (strcmp(linep[i], linep[pivotIndex]) <= 0) {
			if (firstOnIndex == -1) {
				swap_2(linep, low, i);
				offIndex = i;
			}
			else {
				swap_2(linep, i, firstOnIndex);
				offIndex = firstOnIndex;
				firstOnIndex = i;
			}
			lastOffindex = offIndex;
		}
		else {
			if (countFirst == 1) {
				firstOnIndex = i;
				countFirst++;
			}
		}
	}
	swap_2(linep, pivotIndex, lastOffindex);
	pivotIndex = lastOffindex;
	quicksort(linep, low, pivotIndex - 1);
	quicksort(linep, pivotIndex + 2, high);
}

void swap_2(char *p[], int index1, int index2) {
	int *temp;
	temp = p[index1];
	p[index1] = p[index2];
	p[index2] = temp;
}

