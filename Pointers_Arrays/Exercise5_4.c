/* Function strend: return 1 if t at end of string s, return 0 otherwise */
#include <stdio.h>
#include <string.h>

int strlen5_4(char *ps);

static int strend(char *s, char *t) {
	int countlen = 0, belongTo = 0, end = 0;
	int lent = strlen5_4(t);
	int lens = strlen5_4(s);

	while (*s != '\0') {
		if (*s == *t) {
			while (*s == *t && *s != '\0' && *t != '\0') {
				s++;
				t++;
				countlen++;
			}
			if (countlen == lent) {
				belongTo = 1;
				if (*s == '\0') {
					end = 1;
				}
				t = t - countlen;
				countlen = 0;
			}
		}
		else {
			s++;
		}
	}
	return end;
}

static int strlen5_4(char *ps) {
	int len;

	for (len = 0; *ps != '\0'; ps++) {
		len++;
	}

	return len;
}