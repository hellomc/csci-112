#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fpin;

int main() {
	char ch;
	// Standard C declares variables at beginning before fopen.

	fpin = fopen("txtfile.txt", "r");

	// Important to have this error message if file cannot be found.
	if (fpin == NULL) {
		printf("Error: File txtfile.txt could not be opened.");
		fprintf(fpin, "Error: File txtfile.txt could not be opened.");
		exit(-1);
	}

	while ((ch = fgetc(fpin)) != EOF) {
		if (islower(ch)) {
			ch = toupper(ch); // toupper is built-in function that makes char uppercase
		}
		putchar(ch);
	}

	fclose(fpin);
	getchar();
	return 0;
}
