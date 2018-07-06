/* Author: Michelle Adea
Date: 2018 July 5
Description: Shows example of how to write a function.
*/

#include <stdio.h>

// Step 1 - Define function prototype
double area_rectangle(double a, double b);

int main()
{
	double x, y;
	double z;

	x = 10.0;
	y = 20.0;

	z = area_rectangle(x, y); // Step 2 - Call function
}

// Step 3 - Function implementation/definition
double area_rectangle(double a, double b)
{
	double temp;
	temp = a * b;
	return temp;
}
