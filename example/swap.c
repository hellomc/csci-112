/*	Author: Michelle Adea
Date: 2018 July 19
Description: Swap values of two variables using a function

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *x, int *y);
// Indirection operator. At address x and y are integers.

int main()
{
	int a = 10;
	int b = 20;

	printf("Before the swap function return: a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf("After the swap function return: a=%d b=%d\n", a, b);
	getchar();
	return 0;
}

// Increment both variables using address(&) and indirection(*) operators.
void swap(int *x, int *y) {
	int temp;

	printf("In function before the swap: *x=%d *y=%d\n", *x, *y); // Prints new values of x and y.

	temp = *x; // Temp assigned address of x.
	*x = *y; // Assign x with y value.
	*y = temp;

	printf("In function after the swap: *x=%d *y=%d\n", *x, *y); // Prints new values of x and y.
	return;
}
