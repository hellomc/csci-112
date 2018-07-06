#include <stdio.h>

int x = 10;

void outx(void);

int main()
{
	int x = 40;
	{
		int x = 20; //local1
		printf("xlocal1=%d\n", x);
	}
	{
		int x = 30; //local2
		printf("xlocal2=%d\n", x);
	}
	{
		extern int x; // global
		printf("xglobal=%d\n", x);
	}

	printf("xlocal=%d\n", x);
	outx();
	return(0);
}

void outx(void)
{
	printf("xfunc=%d\n", x);
	return;
}
