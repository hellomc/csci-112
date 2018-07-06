/* Author: Michelle Adea
Date: 2018 July 5
Description: Shows example of how to write a function.
*/

#include <stdio.h>

// Step 1 - Define function prototype
void increment(double a);

int main()
{
	double x, y;
	double z;

	x = 10.0;
	y = 20.0;

	increment(x); // Step 2 - Call function
	printf("x=%lf\n", x);
}

// Step 3 - Function implementation/definition
void increment(double a)
{
	a++;
	printf("a=%lf\n", a);
	return;
}
