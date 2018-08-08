/*	Author: Michelle Adea
	Date: 2018 Aug 7
	Description: Use of structures
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct _student{
	char fname[30];
	char lname[30];
	int id;
	//STUDENT *next; STUDENT not yet defined until end.
	struct _student *next;
} STUDENT;

int main(int argc, char *argv[]) {
	STUDENT *s;

	s = (STUDENT *)malloc(sizeof(STUDENT));

	// Initializes fields of the structure student
	/*(*s).id = 123456;
	strcpy((*s).fname, "John");
	strcpy((*s).lname, "Doe");*/

	// Pointer field arrow selection operator
	s->id = 123456;
	strcpy(s->fname, "John");
	strcpy(s->lname, "Doe");
	s->next = NULL;

	//Output fields.
	printf("First Name: %s\n", s->fname);
	printf("Last Name: %s\n", s->lname);
	printf("Student ID: %d\n", s->id);

	free(s);
	getchar();
	return 0;
}
