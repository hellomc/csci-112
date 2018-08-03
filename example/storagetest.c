/*	Author: Michelle Adea
	Date: 2018 Aug 2
	Description: Reviewing Local and Global Variables
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void foo();

int x = 7; // declared as global

int main() {
	{
		int x;
		x = 5;
		printf("%d\n", x);
		foo();
	}
	
	/*{
		extern int x;
		printf("%d\n", x);
	}

	{
	int x; // this x is not associated with above x. created separately. AUTOMATIC variables.
	x = 8;
	printf("%d\n", x);
	}*/

	getchar();
	return 0;
}

/*void foo(int a) {
	static int b = 3; // instead of being stored in stack, stored in data segment
	b++; // with static, b will be incremented by 1 each time the function is called
	printf("%d\n", a + b);
	//printf("%d\n", x); // x is not visible within this function
	return;
}*/

void foo() {
	register int i;
	for (i = 0; i < 10000000; i++) {

	}
	return;
}
