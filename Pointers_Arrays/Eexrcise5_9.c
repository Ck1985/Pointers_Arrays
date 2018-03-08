/* Rewrite function day_of_year and month_day by using pointers instead of indexing */
#include <stdio.h>

static int *notLeafp[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static int *leafp[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static int *daytab5_9[] = { notLeafp, leafp };

/* Function day_of_year: set day of year from month and day */
int day_of_year5_9(int year, int month, int day) {
	int leaf;

	if (year < 1752 || month > 12 || month < 1 || day < 1) {
		return -1;
	}
	leaf = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	int check = *(daytab5_9[leaf] + month);
	if (day > check)
	{
		return -1;
	}
	for (int m = 1; m < month; m++) {
		day += *(daytab5_9[leaf] + m);
	}

	return day;
}

/* Function month_day5_9: set month and day from day of year */
void month_day5_9(int year, int day_of_year, int *monthp, int *dayp) {
	int leaf, i;

	if (year < 1752 || day_of_year < 1) {
		return -1;
	}
	leaf = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	if (leaf && day_of_year > 366 || !leaf && day_of_year > 365) {
		return -1;
	}
	for (i = 1; day_of_year > *(daytab5_9[leaf] + i); i++) {
		day_of_year -= *(daytab5_9[leaf] + i);
	}
	*monthp = i;
	*dayp = day_of_year;
}
