#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

int readlines(char *linesptr[], int maxlen);
int readlines5_7(char *linesprt[], int maxlen, char allocbuf[], int allocsize);
void writelines(char *linesptr[], int nlines);
int getline(char s[], int limit);
char *myalloc(int n);
void quicksort(char *p[], int low, int high);
void swap_2(char *p[], int index1, int index2);
