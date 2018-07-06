#include <stdio.h>


int main()
{
	char x = 3;
	char negx = -x;
	unsigned char y = negx;
	printf("%d\n", negx); //prints decimal number
	printf("%d\n", y); //prints out unsigned character
	getchar();
	return(0);
}
