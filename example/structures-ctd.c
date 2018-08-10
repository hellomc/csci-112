#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
// Describe structure as blueprint outside of main.
// Typically create new data type for structure

typedef struct {
	int b;
	char bb;
} MYSUB;

typedef struct {
	int a;
	char b;
	/*Nesting structures.
	struct {
		int b;
		char bb;
	} g;
	MYSUB g;
} MYSTRUCT;

int main() {
	// Describes data type. X is variable identifier.
	struct {
		int a;
		char b;
	} X;

	X.a
		X.b
		

	MYSTRUCT X = { 4, 'B', { 9, 'W'} };
	// Calling from nested structures X.g.bb
}
*/

typedef struct {
	char street[20];
	char city[20];
} ADDRESS;

typedef struct _STUDENT{
	int id;
	char fname[50];
	char lname[50];
	ADDRESS home;
	struct _STUDENT *next;
} STUDENT;

int main() {
	STUDENT *i;
	STUDENT *q;
	
	STUDENT student1 = { 123, "John", "Doe", {"1 Wilder Dr", "Carson"}, NULL };
	STUDENT student2 = { 234, "Jane", "Smith", {"55 Panem Way", "Carson"}, NULL };
	STUDENT student3 = { 345, "Mary", "Kane", {"49 Lilac St", "Carson"}, NULL };

	// Creates new student.
	q = (STUDENT *)malloc(sizeof(STUDENT));

	// for linked list need to assign pointer to second student in first student structure
	student1.next = &student2;
	student2.next = &student3;
	student3.next = NULL;// Closes list.

	// pointer field selection operator
	for (i = &student1; i; i=i->next) {
		printf("%s\n", i->fname);
		printf("%s\n", i->home.street); // getting info from nested structure
	}

	getchar();
	return;
}
