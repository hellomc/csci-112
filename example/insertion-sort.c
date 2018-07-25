/* Working with Arrays
- Print array
- Go through array and reorder elements from smallest to largest
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int x[], int size);

int main() {
	int x[8] = {3, 6, 3, 2, 8, 23, 1, 5};
	int i;
	for (i = 0; i < 8; i++)
		printf("%d ", x[i]);
	printf("\n");

	insertionSort(x, 8);
	for (i = 0; i < 8; i++)
		printf("%d ", x[i]);
	printf("\n");

	getchar();
	return 0;
}

void insertionSort(int x[], int size) {
	int i, j; // One variable is an index that tracks elements sorted, other is a check
	int temp;

	for (i = 1; i < size; i++) // Starts at second element
	{
		temp = x[i];
		j = i - 1;
		while (j >= 0 && temp < x[j]) {
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = temp;
	}

	return;
}
