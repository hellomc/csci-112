/*	Author: Michelle Adea
	Date: 2018 July 31
	Description: Example of pointers
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int mystrlen(char *s);
//int mystrlen(char s[]); can alternatively be used
void mystrcpy(char *d, char *s); // (destination, source)

int main() {
	char str[100] = "CSCI112";
	char str2[100];
	printf("%d\n", mystrlen(str)); // expect value of 7.
	mystrcpy(str2, str);
	str2[4] = '\0'; // inserts terminating zero. first terminating zero marks end of string
	printf("%s\n", str2);

	getchar();
	return 0;
}

int mystrlen(char *s) {
	int i = 0;

	// while array is not equal to the terminating zero
	//while (s[i] != '\0')
	// use boolean logic s[i] is true until s[i] = '\0' which is false
	//while (s[i])
	//	i++;

	for (i = 0; *(s + i); ++i); // Use pointer as variable
	return i;
}

void mystrcpy(char *d, char *s) {
	int i;
	for (i = 0; s[i]; i++)
		d[i] = s[i];
	d[i] = '\0'; // without this terminating value str will continue
	return;
}
