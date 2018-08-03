/*	Author: Michelle Adea
	Date: 2018 Aug 2
	Description: Manipulating strings.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

FILE *fpin, *fpout;

int main(int argc, char *argv[]) {
	/*printf("The number of program arguments is %d\n", argc);
	printf("The zero indexed argument is the program name: %s\n", argv[0]);
	printf("The first indexed argument is the first argument: %s\n", argv[1]);
	printf("The second indexed argument is the second argument: %s\n", argv[2]);
	*/
	char ch;

	if (argc != 3) {
		printf("Usage is mycopy.exe sourfilename destinationfilename");
		exit(-1);
	}

	fpin = fopen(argv[1], "r"); // Opening file1 with read command.
	if (!fpin) {
		printf("Unable to open file %s for input", argv[1]);
		exit(-1);
	}

	fpout = fopen(argv[2], "w"); // Creating file2 with write command.
	if (!fpout) {
		printf("Unable to open file %s for input", argv[2]);
		exit(-1);
	}

	while ((ch = fgetc(fpin)) != EOF) {
		fputc(ch, fpout);
	}

	fclose(fpin);
	fclose(fpout);

	getchar();
	return 0;
}
