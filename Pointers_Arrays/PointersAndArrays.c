/* function strlen: return length of string s */

static int strlen(char *ps) {
	int len;

	for (len = 0; *ps != '\0'; /*ps = ps + 1*/ ps++ ) {
		len++;
	}
	return len;
}