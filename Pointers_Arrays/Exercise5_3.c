/* Function strcat: Version Pointer copy string t to end of string s */

static void mystrcat(char *s, char *t) {
	while (*s != '\0') {
		s++;
	}
	while (*s++ = *t++)
		;
}