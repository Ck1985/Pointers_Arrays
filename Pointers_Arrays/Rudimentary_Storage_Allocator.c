/* This is rudimentary storage allocator involves two routines : alloc and afree */
#include <stdio.h>

#define ALLOCSIZE 10000		/* size of available space */

static char allocbuf[ALLOCSIZE];   /* Storage for alloc */
static char *allocp = allocbuf;    /* variable pointer *allocp points to array allocbuf, actually it points to address beginning of array allocbuf */
// Or we can initialize variable pointer *allocp follow:
//static char *allocp = &allocbuf[0];

//Function alloc(n): return *p that points to n-consecutive character position:
char *alloc(int n) {		// Return a pointer points to n characters
	if (allocbuf - allocp + ALLOCSIZE >= n) {
		allocp += n;
		return allocp - n;
	}
	else {
		return 0;
	}
}

//Funtion afree(p): releases storage so it can be used later:
void afree(char *p) {		// Free storage pointed by p pointer
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}
}