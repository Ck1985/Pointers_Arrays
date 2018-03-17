/* function find: print lines matches pattern from 1st arguments */
#include <stdio.h>
#include <string.h>
#include "CommandLinesArguments.h"

#define MAXLINE 1000

/*main(int argc, char *argv[]) {
	/*char line[MAXLINE];
	int found = 0;

	if (argc != 2) {
		printf("Usage: find pattern\n");
	}
	else {
		while (getline2(line, MAXLINE) > 0) {
			if (strstr(line, argv[1]) != NULL) {
				printf("%s\n", line);
				found++;
			}
		}
	}

	return found;*/

	/*char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (c = (*++argv)[0]) == '-') {
		while ((c = *++argv[0])) {
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: Illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}
	if (argc != 1) {
		printf("Usage: find -x -n pattern\n");
	}
	else {
		while (getline2(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number) {
					printf("%ld:", lineno);
				}
				printf("%s", line);
				found++;
			}
		}
	}
	/*char arrstr[][3] = {
		"abc",
		"def",
	};
	char(*p)[3];
	p = arrstr;

	printf("%c\n", *++p[0]);*/

	/*char c1 = (*++argv)[0];
	char c2 = *++argv[0];

	printf("%c%c", c1, c2);*/

	//return found;
//}
