/* Rewrite function: getline, atoi, itoa, reverse, strindex, getop using pointer */
#include <stdio.h>
#include <ctype.h>

/* Function getline: read a line into string s, return length */
static int getline5_6(char *ps, int limit) {
	int length = 0, c;

	while (((c = getchar()) != EOF && length++ < limit && c != '\n')) {
		*ps++ = c;
	}
	if (c == '\n') {
		*ps = '\n';
	}
	*ps = '\0';

	return length;
}

/* Function atoi: convert s to integer */
static int atoi5_6(char *ps) {
	int result = 0;

	while (*ps >= '0' && *ps <= '9') {
		result = 10 * result + (*ps - '0');
		ps++;
	}

	return result;
}

/* Function atoiVer2: Convert s to integer */
static int atoi5_6Ver2(char *ps) {
	int sign, result = 0;

	while (isspace(*ps))
		ps++;
	sign = ((*ps == '-') ? -1 : 1);
	if (*ps == '+' || *ps == '-')
		ps++;
	while (isdigit(*ps)) {
		result = 10 * result + (*ps++ - '0');
	}

	return sign * result;
}

/* Function reverse: Reverse string s in place */
static void reverse5_6(char *ps) {
	char *initps = ps, *endps = ps;
	endps = endps + strlen5_6(ps) - 1;

	while (initps < endps) {
		char temp = *initps;
		*initps = *endps;
		*endps = temp;
		initps++;
		endps--;
	}
}

/* Function strindex: return index of string t in string s, -1 if none */
static int strindex5_6(char *ps, char *pt) {
	int index = 0, count = 0;
	int lent = strlen5_6(pt);
	char *initpt = pt;

	while (*ps != '\0') {
		pt = initpt;
		count = 0;
		while (*ps == *pt && *pt != '\0') {
			count++;
			ps++;
			pt++;
			index++;
		}
		if (count == lent) {
			return index - count + 1;
		}
		ps++;
		index++;
	}

	return -1;
}

/*Function strlen5_6: return length of string */
static int strlen5_6(char *ps) {
	char *initps = ps, length = 0;

	while (*ps++ != '\0') {
		length++;
	}

	return length;
}