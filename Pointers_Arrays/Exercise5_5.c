#include <stdio.h>
#include <string.h>

int strlen5_5(char *ps);

static char *mystrncpy(char *s, const char *t, int n) {
	int count;
	char *initAdress = s;
	// Or Initialize as: 
	//initAdress = s;

	int lens = strlen5_5(s), lent = strlen5_5(t);

	if (lens >= lent) {
		if (n <= lent) {
			for (count = 1; count <= n; count++) {
				*s++ = *t++;
			}
		}
		else {
			for (count = 1; count <= n; count++) {
				if (count > lent) {
					*s++ = '\0';
				}
				else {
					*s++ = *t++;
				}
			}
		}
	}
	else {
		for (count = 1; count <= n; count++) {
			*s++ = *t++;
		}
	}

	return initAdress;
}

static char *mystrncat(char *s, const char *t, int n) {
	int count;
	int lens = strlen5_5(s), lent = strlen5_5(t);
	char *initpointerdest;

	initpointerdest = s;
	s = s + lens - 1;

	for (count = 1; count <= n; count++) {
		if (count > lent) {
			*s++ = '\0';
		}
		else {
			*s++ = *t++;
		}
	}

	return initpointerdest;
}

static int mystrncmp(const char *rhs, const char *lhs, int n) {
	int count, differ;

	for (count = 1; *rhs == *lhs && count <= n; count++) {
		rhs++;
		lhs++;
	}
	differ =  *rhs - *lhs;
	if (differ > 0) {
		return 1;
	}
	else if (differ == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

static int strlen5_5(char *ps) {
	char *p = ps;

	while (*p++ != '\0')
		;
	return p - ps;
}

