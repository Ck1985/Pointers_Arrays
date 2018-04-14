#include <stdlib.h>
#include "sorting_line.h"
#include "Pointers_To_Functions.h"

void qsortPTF(void *v[], int left, int right, int (*comp)(void *, void *)) {
	int i, last;

	void swapPTF(void *v[], int, int);
	if (left >= right) {
		return;
	}
	swapPTF(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0) {
			swapPTF(v, ++last, i);
		}
	}
	swapPTF(v, left, last);
	qsortPTF(v, left, last - 1, comp);
	qsortPTF(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2) {
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2) {
		return -1;
	}
	else if (v1 > v2) {
		return 1;
	}
	else {
		return 0;
	}
}

void swapPTF(void *v[], int i, int j) {
	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}