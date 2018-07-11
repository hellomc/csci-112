/*Author: Michelle Adea
Date: 2018 July 10
Description: Class example of factorial function.
*/

//Header Files
#include <stdio.h>

int fact(int n); // 1) Function Prototype = Defines interface.

//Body 2) Function Definition
int main()
{
	int n = 3;
	int f;
	f = fact(n);
	printf("The factorial of %d is %d\n", n, f);
	return 0;
}

// 3) Function Implementation = same format as main function
int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return fact(n - 1) * n;
}
