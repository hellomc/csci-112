/*  Author: Michelle Adea
 
    Date: 2018 July 27
 
    Description: Write a program that does the following:
    - Converts a calendar date into a Julian date
    - Converts a Julian date into a calendar date
    - EC Computes the number of days between any two calendar dates.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *fpOut;

/* Function Headers
 displayMenu        displays selection menu and prompts user for selection
 getCalendarDate    prompts and gets calendar date from user
 getJulianDate      prompts and gets Julian date from user
 toCalendar         converts Julian date into calendar date
 toJulian           converts calendar date into Julian date
 isLeapYear         adds extra day in February if it is leap year
 daysBetweenDates   calculates # of days between 2 calendar dates
 */

int displayMenu(int *option);
int isLeapYear(int year);
void getCalendarDate(int *cmonth, int *cday, int *cyear);
int toJulian(int *cmonth, int *cday, int *cyear);
void getJulianDate(int *jday, int *jyear);
int toCalendar(int *jday, int *jyear);
int daysBetweenDates(int *month1, int *day1, int *year1, int *month2, int *day2, int *year2);

// -----------------------------------------------------------

int main() {
    int option, cmonth, cday, cyear;
    int jday, jyear;
    int month1, day1, year1, month2, day2, year2;
    
    fpOut = fopen("date-lab-mca.txt", "w");
    
    displayMenu(&option);
    
    do {
        if (option == 1) {
            getCalendarDate(&cmonth, &cday, &cyear);
            toJulian(&cmonth, &cday, &cyear);
        } else if (option == 2) {
            getJulianDate(&jday, &jyear);
            toCalendar(&jday, &jyear);
        } else if (option == 3) {
            daysBetweenDates(&month1, &day1, &year1, &month2, &day2, &year2);
        } else {
            exit(1);
        }
    } while (displayMenu(&option) && 1);
        
    fclose(fpOut);
    getchar();
    getchar();
    return 0;
}

// -----------------------------------------------------------

// Function definitions
int displayMenu(int *option) {
    printf("DATE SELECTION MENU\n\n");
    
    printf("(1) Convert calendar date into Julian date\n");
    printf("(2) Convert Julian date into calendar date\n");
    printf("(3) Compute days between two calendar dates\n");
    printf("(4) Exit program\n");
    
    printf("\nENTER SELECTION(1-4):");
    scanf("%d", option); // Variable is already passed by reference, no need for (&) operator.
    
    if (*option >= 1 && *option < 4) {
        printf("%d\n", *option);
    } else if (*option == 4) {
        printf("User has exited the program.\n");
        //fprintf(fpOut, "User has exited the program.\n");
    }
    else {
        printf("User entered invalid selection.\n");
        fprintf(fpOut, "User entered invalid selection.\n");
    }
    
    return *option;
}

int isLeapYear(int year) {
    return ((!(year % 4) && year % 100) || !(year % 400));
}

void getCalendarDate(int *cmonth, int *cday, int *cyear) {
    printf("Enter a month(MM):");
    scanf("%d", cmonth);
    
    printf("Enter a day(DD):");
    scanf("%d", cday);
    
    printf("Enter a year(YYYY):");
    scanf("%d", cyear);
    
    printf("%-20s%30s\n", "Calendar Date", "Julian Date");
    fprintf(fpOut, "%-20s%30s\n", "Calendar Date", "Julian Date");
    printf("%d/%d/%d", *cmonth, *cday, *cyear);
    fprintf(fpOut, "%d/%d/%d", *cmonth, *cday, *cyear);
    
    return;
}

int toJulian(int *cmonth, int *cday, int *cyear) {
    int numDays = 0;
    int year = *cyear;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int i;
    if (*cmonth > 2 && *cday != 29)
        numDays += isLeapYear(*cyear);
    numDays += *cday;
    for (i = 0; i < (*cmonth-1); i++) {
        numDays += daysInMonth[i];
    }
    
    printf("%30d%10d\n\n", numDays, year);
    fprintf(fpOut, "%30d%10d\n\n", numDays, year);
    
    return numDays;
}

void getJulianDate(int *jday, int *jyear) {
    printf("Enter a Julian day (DDD):");
    scanf("%d", jday);
    
    printf("Enter a year (YYYY):");
    scanf("%d", jyear);
    
    printf("%-20s%20s\n", "Julian Date", "Calendar Date");
    fprintf(fpOut, "%-20s%20s\n", "Julian Date", "Calendar Date");
    printf("%-6d%-10d", *jday, *jyear);
    fprintf(fpOut, "%-6d%-10d", *jday, *jyear);
}

int toCalendar(int *jday, int *jyear) {
    int month, day, year;
    year = *jyear;
    month = 0;
    day = 0;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapdaysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
    int i;
    for (i = 0; i <= 12; i++) {
        if (isLeapYear(year) == 1){
            if (*jday < leapdaysInMonth[i]) {
                month = i + 1;
                if (*jday == 0) {
                    month = i;
                    day = leapdaysInMonth[i-1];
                } else {
                    day = *jday;
                }
                break;
            } else {
                *jday -= leapdaysInMonth[i];
            }
        } else {
            if (*jday < daysInMonth[i]) {
                month = i + 1;
                if (*jday == 0) {
                    month = i;
                    day = daysInMonth[i-1];
                } else {
                    day = *jday;
                }
                break;
            } else {
                *jday -= daysInMonth[i];
            }
        }
    }
 
    printf("%15d/%d/%d\n\n", month, day, year);
    fprintf(fpOut, "%15d/%d/%d\n\n", month, day, year);
    
    return month;
}

// Calculate the difference of each date with 1/1/1900 then sum the two differences.
int daysBetweenDates(int *month1, int *day1, int *year1, int *month2, int *day2, int *year2) {
    int tempd1, tempd2, totald1, totald2, totalDays, julianday, julianyear, i;
    
    tempd1 = 0;
    tempd2 = 0;
    totald1 = 0;
    totald2 = 0;
    julianday = 1;
    julianyear = 1900;
    
    // Prompts user to enter 2 separate dates.
    printf("\nDate 1\n");
    printf("Enter a month(MM):");
    scanf("%d", month1);
    
    printf("Enter a day(DD):");
    scanf("%d", day1);
    
    printf("Enter a year(YYYY):");
    scanf("%d", year1);
    printf("\nDate 2\n");
    printf("Enter a month(MM):");
    scanf("%d", month2);
    
    printf("Enter a day(DD):");
    scanf("%d", day2);
    
    printf("Enter a year(YYYY):");
    scanf("%d", year2);
    
    //!!!PROBLEM AREA: CALCULATING DAYS BETWEEN DATES.
    // Returns number of days in given year.
    tempd1 = toJulian(month1, day1, year1);
    printf("%d\n", tempd1);
    // For each year, before original year, determines if it's a leap year.
    for (i = (*year1-1); i >= julianyear; i--) {
        if (isLeapYear(i) == 1) {
            totald1 += 366;
        } else {
            totald1 += 365;
        }
    }
    printf("%d\n", totald1);
    // Adds tempd1 and totald1;
    totald1 += tempd1;
    // Takes difference with Julian day 1 for 1/1/1900.
    totald1 -= julianday;
    printf("%d\n", totald1);
    
    //Repeat above.
    tempd2 = toJulian(month2, day2, year2);
    printf("%d\n", tempd2);
    for (i = (*year2-1); i >= julianyear; i--) {
        if (isLeapYear(i) == 1) {
            totald2 += 366;
        } else {
            totald2 += 365;
        }
    }
    printf("%d\n", totald2);
    totald2 += tempd2;
    totald2 -= 1;
    printf("%d\n", totald2);
    
    totalDays = abs(totald2 - totald1);
 
    printf("%-10s%10s%30s\n", "Date 1", "Date 2", "Total Days between Dates");
    fprintf(fpOut, "%-10s%10s%30s\n", "Date 1", "Date 2", "Total Days between Dates");
    printf("%d/%d/%d%5d/%d/%d%10d\n", *month1, *day1, *year1, *month2, *day2, *year2, totalDays);
    fprintf(fpOut, "%d/%d/%d%5d/%d/%d%10d\n", *month1, *day1, *year1, *month2, *day2, *year2, totalDays);
    
    return totalDays;
}
// -----------------------------------------------------------
