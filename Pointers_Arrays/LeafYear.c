/* Convert from day of year to day_month and reverse */
#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* function day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day) {
	int leafYear;

	if (year < 1752 || month > 12 || month < 1 || day < 1) {
		return -1;
	}
	leafYear = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
	if (day > daytab[leafYear][month]) {
		return -1;
	}
	for (int m = 1; m < month; m++) {
		day += daytab[leafYear][m];
	}

	return day;
}

/* function month_day: set month and day from day of year */
void month_day(int year, int day_of_year, int *monthp, int *dayp) {
	int leafYear, i;

	if (year < 1752 || day_of_year < 1) {
		return -1;
	}
	leafYear = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
	if ((leafYear && day_of_year > 366) || (!leafYear && day_of_year > 365)) {
		return -1;
	}
	for (i = 1; day_of_year > daytab[leafYear][i]; i++) {
		day_of_year -= daytab[leafYear][i];
	}

	*monthp = i;
	*dayp = day_of_year;
}

