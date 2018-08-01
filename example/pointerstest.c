/*	Author: Michelle Adea
	Date: 2018 July 31
	Description: Example of pointers
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int x[10] = {6, 3, 5, 8, 2, 1, 6, 7, 4};

	int *p;
	//char *q;
	//q = 'A';
	//printf("%p\n", q);
	
	// Address of first element in above array.
	//p = x;
	// Prints value of first element in above array.
	//printf("%d\n", *p);
	// Prints 3rd element in the array.
	//printf("%d\n", x[2]);
	// Another way to print 3rd element in array.
	//printf("%d\n", *(p + 2));

	//p initialized to 4th element of array.
	//p = x + 3;
	//  Add 2, prints 6th element.
	//printf("%d\n", *(p + 2));

	//p initialized to 4th element of array.
	p = x + 3;
	//p value assigned 3rd element of array.
	p--;
	// p value points to 5th element of array.
	printf("%d\n", *(p + 2));

	getchar();
	return 0;
}
