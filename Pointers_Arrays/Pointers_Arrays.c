#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "GetIntFunction.c"
#include "Exercise5_1.c"
#include "Exercise5_2.c"
#include "Exercise5_3.c"
#include "Exercise5_4.c"
#include "Exercise5_5.c"
#include "Exercise5_6.c"
#include "PointersAndArrays.c"
#include "calc5_6.h"
#include "sorting_line.h"
#include "leafYear.h"

#define SIZE 100
#define MAXOP 100
#define MAXLINES 5000		/* max #line to be sorted */
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *allocbuf[ALLOCSIZE];
char *lineptr[MAXLINES];    /* pointers points to text line */

void swap(int *p1, int *p2);
int getint(int *pn);
int getint5_1(int *pn);
int strlen(char *ps);
void f(char *ps);
int strlen_2(char *s);
void strcpy_1(char *s, char *t);
void strcpy_2(char *s, char *t);
void strcpy_3(char *s, char *t);
void strcpy_4(char *s, char *t);
int strcmp_1(char *s, char *t);
int strcmp_2(char *s, char *t);
void mystrcat(char *s, char *t);
int strend(char *s, char *t);
char *mystrncpy(char *s, const char *t, int n);
char *mystrncat(char *s, const char *t, int n);
int mystrncmp(const char *s, const char *t, int n);
int strlen5_5(char *ps);
int getline5_6(char *ps, int limit);
int atoi5_6(char *ps);
int atoi5_6Ver2(char *ps);
void reverse5_6(char *ps);
int strindex5_6(char *ps, char *pt);
int strlen5_6(char *ps);
char *month_name(int n);

int main() {
	/* ----------- Pointers and Adresses ------------- */
	/*char c = 'a';
	char p = &c; // Note: if we declare this style so that p is not a pointer which point to c.
	char *p2;*/
	// *p2 = &c; Error
	//printf("%x\n", *p); Error compile because p is not pointer so *p is incorrect 
	// Operand of * operator must be pointer.
	//p2 = &c;
	//printf("%x\n", p2);
	//printf("%c\n", *p2);

	/*int x = 1, y = 2, z[10];
	int *ip;    // This is formal declaration of pointer.
	            // ip is a pointer point to int

	ip = &x;    // ip points to x now
	y = *ip;    // y = 1 now
	printf("%d\n", y);
	*ip = 0;   // x now = 0
	printf("%d\n", x);
	ip = &z[0];  // ip now points z[0];
	int *iq;
	iq = ip;    // iq pointer points to whatever ip points to*/

	/* ----------------------------------------------- */

	/* ------------ Pointer And Function Arguments------------ */
	// Swap 2 variables by using pointers:
	/*int a = 5, b = 6;
	printf("Before swap a = %d & b = %d\n", a, b);
	int *p1, *p2;
	p1 = &a;
	p2 = &b;
	swap(p1, p2);
	printf("After swap a = %d & b = %d\n", a, b);*/

	/*int n, arr[SIZE];
	
	for (n = 0; n < SIZE && getint(&arr[n]) != EOF; n++)
		;
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("%\n");*/


	//Exercise5_1
	/*int n, arr[SIZE];

	for (n = 0; n < SIZE && getint5_1(&arr[n]) != EOF; n++)
		;

	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	// Exercise5_2
	/*float getFloat(int *pn), arr[SIZE];
	int n;

	for (n = 0; n < SIZE && getFloat(&arr[n]) != EOF; n++)
		;
	for (int i = 0; i < 10; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");*/

	/* ------------------------------------------------------- */

	/* ------------ Pointers And Arrays --------------- */
	/*int arr[10]; // declaretion an array arr which has 10 elements and type array is int
	int *pa;     // declaretion of pointer pa has type is int

	// The assigement
	pa = &arr[0];  // sets pa points to the 0 element of array arr because pa variable hold address of arr[0]
	// Now the assigment
	int x = *pa;   // will copies content (value) of arr[0] to x
	int i;
	// if *pa points to element n of arr
	pa = &arr[4]; // Ex: pa points to 4th element of array arr
	pa + 1;      // points to element 5th 
	pa + i; // points to ith element after 4th so on...
	pa - i; // ponits to ith element before 4th ...
	// And if pa points to arr[0] then
	*(pa + 1); // refers to contens (value) of arr[1];
	*(pa + i); // refers to content (value) of arr[i];

	// Because name of array is an anonym for initial elemnt oc array arr so that
	// statement:
	pa = &arr[0]; 
	// equaleve to
	pa = arr;
	// A refers to arr[i] can be written *(arr + i) ( *(pa + i) ) so that
	// 2 form &arr[i] and (arr + i) are equivLent.
	// (arr + i) is address of i-th element beyond arr
	// pa[i] is equilavent *(pa + i)

	// There is one difference between array name and a pointer must be keep in mind
	// Beacause a pointer is variable so 
	pa = arr; // legal
	pa++;     // legal
	// but name of array arr is not variable so
	//arr = pa; // Ilegal
	// arr++;   // Ilegal

	// When name of array passed to function what is passed is location of initialie element (first element)
	// So the parametter array name must be a pointer, that is a variable contants an address
	char myName[] = "xuan quy";
	char *ps;
	//ps = myName;
	// Or:
	ps = &myName[0];
	printf("%d\n", strlen(ps));
	printf("%d\n", strlen("12345"));
	printf("%d\n", strlen(myName));

	// we can pass a part of array to function by pass pointer that points to beginning of array
	// Ex:
	char str[] = "123456";
	char *ps2, *ps3;
	ps2 = &str[3];
	ps3 = &str[0];
	f(ps2);      // Ok
	f(&str[3]); // Ok
	f(ps3 + 3);  // Ok
	// it is also possible index backward f[-1], f[-2]... 
    f(ps2 - 3);*/
	/* ------------------------------------------------ */

    /* ------------ Address arithmetic ---------------- */
	// *alloc(int n);
	// afree(char *p);
	// strlen_2(char *s);
    /* ------------------------------------------------ */

	/* -------------- Characters Pointers And Functions --------------- */
	/*printf("Character Pointer And Function\n");
	char *pMessage;
	pMessage = "Now it's the time";
	// These is a important difference between two definition:
	char aMessage[] = "This is an array";
	char *pMessage = "This is a pointer";*/

	/*char str1[] = "abc";
	char str2[] = "efgh";
	char *p1 = str1, *p2 = str2;

	strcpy_4(p1, p2);
	printf("%s\n", str1);*/

	/*char desArr[100] = "Cao Xuan Quy ";
	char sourceArr[100] = "Handsome";
	char *pd = desArr;
	char *ps = sourceArr;
	mystrcat(pd, ps);
	printf("%s\n", desArr);*/

	/*char name[] = "12abcdefghxxxabcdxxacbdefg   abcdefgh";
	char pattern[] = "abcdefgh";
	char *ps = name;
	char *t = pattern;

	//printf("%d\n", strlen5_4(ps));
	printf("%d\n", strend(ps, t));*/

	// Testing function strncpy from standard library C language:
	/*char dest[] = "abcdz";
	char src[] = "abcdefghijklmnw";
	char *pdest = dest, *psrc = src;

	//result = mystrncpy(pdest, psrc, 8);
	//result = mystrncat(pdest, psrc, 8);
	//strncpy(pdest, psrc, 3);
	//strncat(pdest, psrc, 8);
	//printf("%s\n", s);
	//printf("%s\n", s);
	//int result = strncmp(pdest, psrc, 6);
	int result = mystrncmp(pdest, psrc, 7);

	printf("%d\n", result);*/
	
	/*char str[10];
	int limit = 9;
	char *ps = str;

	int length = getline5_6(ps, limit);

	printf("%d\n", length);*/

	/*char number[] = "123456789abcdeffvdfv";
	char *ps = number;
	//reverse5_6(ps);
	printf("%s\n", number);*/

	/*char strings[] = "anonymous.vn1985@gmail.com";
	char stringt[] = "ymous";

	char *ps = strings;
	char *pt = stringt;

	int result = strindex5_6(ps, pt);
	printf("%d\n", result);*/

	/*int type;
	double op2;
	char s[MAXOP];
	char *ps = s;

	while ((type = getop5_6(ps)) != EOF) {
		switch (type) {
		case NUMBER:
			push5_6(atof(s));
			break;
		case '+':
			push5_6(pop5_6() + pop5_6());
			break;
		case '*':
			push5_6(pop5_6() * pop5_6());
			break;
		case '-':
			op2 = pop5_6();
			push5_6(pop5_6() - op2);
			break;
		case '/':
			op2 = pop5_6();
			if (op2 != 0.0) {
				push5_6(pop5_6() / op2);
			}
			else {
				printf("Error: Division zero !");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop5_6());
			break;
		default:
			printf("Error: Unknown command %s\n", s);
			break;
		}
	}*/

	
	/* ---------------------------------------------------------------- */

	/* ------------------ Pointer Arrays && Pointers to Pointers -------------------- */
	/*int nlines;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		quicksort(lineptr, 1, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("Error: Input text lines too big to sort\n");
		return 1;
	}*/

	// Exercise5_7.c
	/*int nlines;
	if ((nlines = readlines5_7(lineptr, MAXLINES, allocbuf, ALLOCSIZE)) >= 0) {
		quicksort(lineptr, 1, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("Error: Input text lines too big to sort\n");
		return 1;
	}*/
	/* ------------------------------------------------------------------------------ */

	/* -------------------- Multi-dimension Arrays ------------------------- */
	/*int array1D[] = { 1,2,3,4,5 };
	int num[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	//int *ptr = &num[0][0];
	int *ptr1 = array1D;
	int *ptr2 = array1D + 3;
	int *ptr = num;
	int ROW = 3,
		COLLUMN = 4,
		TOTAL_CELLS = ROW * COLLUMN;
	
	/*for (int i = 0; i < TOTAL_CELLS; i++) {
		printf("%d ", *(ptr + i));
	}
	int ptr0 = num + 0, ptr3 = num + 1;
	ptr + 1;
	//printf("%d %d", ptr + 0, ptr + 1);
	printf("\n");*/

	/*int monthp = 0, dayp = 0;
	month_day(2018, 90, &monthp, &dayp);
	printf("month = %d and day = %d\n", monthp, dayp);*/
	/* --------------------------------------------------------------------- */

	/* ------------------Initialization Pointer Arrays---------------------- */
	// month_name(n);
	/* --------------------------------------------------------------------- */

	/* ------------------ Pointers And Multidimension Arrays ---------------- */
	/*int a[10][20];		// a is a true two dimension array and 200 int-sized location have been set aside.
	int *b[10];			// The defination just only allocator 10 pointers and not initialization them
						// The initialization must be done explicitly.
	a[3][4];
	b[3][4];

	//Ex:
	char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };
	char anme[][15] = { "Illegal month", "Jan", "Feb", "Mar" };*/

	//printf("%d\n", day_of_year5_9(2000, 3, 4));
	/*int monthp = 0;
	int dayp = 0;
	month_day5_9(2000, 64, &monthp, &dayp);
	//int month = monthp;
	//int day = dayp;
	printf("month = %d && day = %d\n", monthp, dayp);*/
	/*int *p;
	int x = 3;
	p = &x;
	printf("%d\n", *p);*/

	/*char *test = "abcdefgh";
	char *test2 = "lmnijk";
	char *arrp[] = { test, test2 };

	char *p = arrp[1];
	char *p1 = p + 2;
	char value = *p1;*/
	/* ---------------------------------------------------------------------- */

	return 0;
}

// Note: Actually when main (calling function) call swap (called function) it takes two copies of 2 pointer
// But 2 copies pointer still pointer two variable (because copies pointers points to two variables)
// So we can still swap value of two variable
// OK Done !!!
void swap(int *p1, int *p2) {
	int temp;
	temp = *p2;		// temp variable hold actually value of variable which pointer p2 points to
	*p2 = *p1;		// change actually value of variable which *p2 points to by let *p2 hold value of variable which *p1 points to
	*p1 = temp;		// Finally change actually value of variable which *p1 ponits to let *p1 hold value of variable which *p2 points to
					// Done 
}

void f(char *ps) {
	printf("%c\n", *ps);
}

//Function strlen_2: return length of string 
int strlen_2(char *s) {
	char *p = s;
	// Or
	//p = s;

	while (*p != '\0') {
		p++;
	}
	return p - s;
}

// Function strcpy_1: Copy t to s, array version subscript
void strcpy_1(char *s, char *t) {
	int i = 0;

	while ((s[i] = t[i]) != '\0') {
		i++;
	}
}

//Function strcpy_2: Copy t to s, pointer version 1
void strcpy_2(char *s, char *t) {
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

//Function strcpy_3: Copy t to s, pointer version 2
void strcpy_3(char *s, char *t) {
	while ((*s++ = *t++) != '\0')
		;
}

//Function strcpy_4: Copy t to s, pointer version 4 remove condition != '\0'
// Because when value of t reach '\0' so dec of null equal 0.
void strcpy_4(char *s, char *t) {
	while (*s++ = *t++)
		;
}

//Function strcmp_1 : index array version return < 0 if s < t, = 0 if s = t and > 0 if s > t
int strcmp_1(char *s, char *t) {
	int i;

	for (i = 0; s[i] == t[i]; i++) {
		if (s[i] == '\0') {
			return 0;
		}
	}
	return s[i] - t[i];
}

// Function strcmp_2: pointer version return < 0 if s < t, = 0 if s = t and > 0 if s > t
int strcmp_2(char *s, char *t) {
	for (; *s = *t; s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}
	return *s - *t;
}

/* function month_name: return name of n-th month */
char *month_name(int n) {
	static char *name[] = {
		"Illegal month",
		"January", "Ferbuary",  "March",
		"April", "May", "June",
		"July", "August", "September",
		"Octorber", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}


