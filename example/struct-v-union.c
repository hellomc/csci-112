// Difference between structure and union

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*typedef struct {
	// structure has 2 fields. 1) integer = 4 bytes 2) char = 4 bytes Total 8 bytes
	int x;
	char y[4];
} S1;
*/

typedef union {
	// structure has 2 fields. 1) integer = 4 bytes 2) char = 4 bytes Sit in same memory space. Every field is on top of each other.
	int x;
	char y[4];
} S1;

void main() {
	S1 s;
	s.x = 0x12345678;
	// Lowest bit is at the end. Letters from char y overwrites int x.
	s.y[0] = 'A';
	s.y[1] = 'B';
	s.y[2] = 'C';
	s.y[3] = 'D';
	// If above is commmented out. Results are 78\n56\n34\n12\n.
	
	printf("%d\n", sizeof(S1));
	printf("%x\n", s.x);
	printf("%x\n", s.y[0]);
	printf("%x\n", s.y[1]);
	printf("%x\n", s.y[2]);
	printf("%x\n", s.y[3]);

	getchar();
	return;
}
