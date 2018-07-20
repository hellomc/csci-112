/*	Author: Michelle Adea
Date: 2018 July 19
Description: Increment 2 variables

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void man_x_y(int *x, int *y);
// Indirection operator. At address x and y are integers.

int main()
{
	int a = 10;
	int b = 20;

	man_x_y(&a, &b);
	printf("a=%d b=%d\n", a, b);
	getchar();
	return 0;
}

// Increment both variables using address(&) and indirection(*) operators.
void man_x_y(int *x, int *y) {
	(*x)++;
	(*y)++;
	printf("x=%d y=%d\n", *x, *y);
	return;
}
