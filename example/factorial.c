/* Author: Michelle Adea
Date: 2018 July 12
Description: Practicing for, while, and do while loops.
*/

#include <stdio.h>

int main()
{
	//int i = 1;

	/*while (i < 100)
	{
		// More efficient than if loop below, repeats cycle 50 times.
		//printf("%d\n", i);
		//i = i + 2;

		if (i % 2)
			printf("%d\n", i);
		i = i + 1;
	}
	*/

	/*while (i < 100)
	{
		if ((i & 2) && (i != 53)) // Skips 53.
			printf("%d\n", i);
		i = i + 1;
	}
	*/

	int i;

	for (i = 1; i < 10; i++)
	{
		if (i == 7)
			break; // Indicates last case. Stops cycle immediately.
			//continue; // Special statement skips over remaining statements in block. Block stops here. Only inside loops
		
		if (i % 2)
			printf("%d\n", i);
	}

	//getchar();
	return 0;
}
