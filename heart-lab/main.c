/*
Author: Michelle Adea
Date: 2018 June	28
Description: Create a function that calculates heart beat per second to heart beats for 50 years.
*/

#define _CRT_SECURE_NO_WARNINGS
//Below variables are defined as constants in this problem.
#define AVG_HB_PER_SEC 1
#define SEC_PER_MIN 60
#define MIN_PER_HR 60
#define HR_PER_DAY 24
#define DAY_PER_YEAR 365
#define NUM_YEAR 50
//Preprocessor to include library stdio.h
#include <stdio.h>

FILE *fp;

long int main() {
	long int hb_50years; //variable for number of heart beats in 50 years

	fp = fopen("heart-lab-mca.txt", "w"); //placed after variable descriptions

	hb_50years = AVG_HB_PER_SEC * SEC_PER_MIN * MIN_PER_HR * HR_PER_DAY * DAY_PER_YEAR * NUM_YEAR;

	printf("In 50 years, a human heart beats %ld times.", hb_50years);
	fprintf(fp, "In 50 years, a human heart beats %ld times.", hb_50years);
	fclose(fp);
	getchar();
	return(0);
}
