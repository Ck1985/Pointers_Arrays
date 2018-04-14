#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exercise5_14.h"

void quicksort5_14(void *linesp[], int low, int high, int (*comp)(void *, void *)) {
	int indexPivot, indexLeftMark, indexRightMark, leftStop = 0, rightStop = 0;
	int indexSwapLeft, indexSwapRight;

	indexPivot = high;
	indexLeftMark = low;
	indexRightMark = high - 1;

	if (low >= high) {
		return;
	}
	else {
		while (indexLeftMark <= indexRightMark) {
			while (comp(linesp[indexLeftMark], linesp[indexPivot]) < 0) {
				indexLeftMark++;
				if (indexLeftMark > high) {
					break;
				}
			}
			leftStop = 1;
			indexSwapLeft = indexLeftMark;
			while (comp(linesp[indexRightMark], linesp[indexPivot]) > 0) {
				indexRightMark--;
				if (indexRightMark < low) {
					break;
				}
			}
			rightStop = 1;
			indexSwapRight = indexRightMark;
			if (leftStop == 1 && rightStop == 1 && (indexLeftMark <= indexRightMark)) {
				swap5_14(linesp, indexSwapLeft, indexSwapRight);
				leftStop = rightStop = 0;
			}
		}
		swap5_14(linesp, indexLeftMark, indexPivot);
		quicksort5_14(linesp, low, indexLeftMark - 1, comp);
		quicksort5_14(linesp, indexLeftMark + 1, high, comp);
	}
}

int readlines5_14(char *linesptr[], int maxlen) {
	int nlines = 0, len;
	char *p, line[MAXLEN5_14];

	while ((len = getline5_14(line, MAXLEN5_14)) > 0) {
		if (nlines >= MAXLINES5_14 || (p = alloc5_14(len)) == NULL) {
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

void writelines5_14(char *linesp[], int nlines) {
	int i;

	for (i = 0; i < nlines; i++) {
		printf("%s\n", linesp[i]);
	}

	printf("\n");
}

void swap5_14(void *p[], int index1, int index2) {
	void *temp;

	temp = p[index1];
	p[index1] = p[index2];
	p[index2] = temp;
}

char *alloc5_14(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else {
		return 0;
	}
}

int getline5_14(char s[], int limit) {
	int c, i;

	for (i = 0, i < limit - 1; (c = getchar()) != EOF && (c != '\n'); i++) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}

int numcmp5_14(void *s1, void *s2) {
	double value1, value2;

	value1 = atof(s1);
	value2 = atof(s2);

	if (value1 > value2) {
		return 1;
	}
	else if (value1 < value2) {
		return -1;
	}
	else {
		return 0;
	}
}