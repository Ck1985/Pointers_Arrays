#define MAXLINES5_14 5000
#define MAXLEN5_14 1000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

void swap5_14(void *p[], int index1, int index2);
void quicksort5_14(void *linesp[], int low, int high, int (*comp)(void *, void *));
int readlines5_14(char *linesptr[], int maxlen);
void writelines5_14(char *lines[], int nlines);
char *alloc5_14(int n);
int getline5_14(char s[], int limit);
int numcmp5_14(void *, void *);
