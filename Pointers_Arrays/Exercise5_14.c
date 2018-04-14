#include <stdio.h>
#include <string.h>
#include "Exercise5_14.h"

int main(int argc, char *argv[]) {
	int nlines = 0;
	int optionComp = 0;
	char *linesptr[MAXLINES5_14];

	if (argc > 1 && strcmp((*argv),"-r")) {
		optionComp = 1;
	}
	if ((nlines = readlines5_14(linesptr, MAXLINES5_14)) >= 0) {
		quicksort5_14((void **) linesptr, 0, nlines - 1, (int (*)(void *, void *)) optionComp ? numcmp5_14 : strcmp);
		writelines5_14(linesptr, nlines);
		return 0;
	}
}