#include <stdio.h>

/* echo command-line arguments: 2th version */
/*main(int argc, char *argv[]) {
	while (--argc > 0) {
		//printf("%s%s", *++argv, (argc > 1) ? " ": "");
		printf((argc > 1) ? "%s " : "%s", *++argv);
	}

	return 0;
}*/