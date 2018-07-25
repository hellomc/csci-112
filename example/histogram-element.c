/* Working with Arrays
- Print array
- Go through array and reorder elements from smallest to largest
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int x[], int size);

int main() {
	int x[8] = {3, 4, 3, 3, 4, 6, 7};
	int h[10];

	int i;
	for (i = 0; i < 10; i++)
		h[i] = 0;

	for (i = 0; i < 7; i++) {
		h[x[i]] = h[x[i]] + 1;
	}
	
	for (i = 0; i < 10; i++)
		printf("%d ", h[i]);
	printf("\n");

	getchar();
	return 0;
}
