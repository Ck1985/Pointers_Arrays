/* Rewrite function day_of_year and month_day by using pointers instead of indexing */
#include <stdio.h>

static char *notLeafp[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char *leafp[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char *daytab5_9[] = { notLeafp, leafp };
