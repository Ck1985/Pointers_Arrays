#define MAXLINES 5000		/* max #lines to be sorted */

char *lineptr[MAXLINES];	/* pointer to text lines */

void qsortPTF(void *v[], int left, int rigth, int(*comp)(void *, void *));
int numcmp(char *, char *);

