/*  Author: Michelle Adea
Date: 2018 July 19
Description: Write five functions for keeping track of various
components: initial balance, deposit, check, summary, and headers
for a checking account.

Make sure to use the indirection operator (*) correctly for
input-output parameters.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

FILE *fpIn;
FILE *fpOut;

// Write function headers.
void outputHeaders(void);
double initialBalance(double amount, double *balance, double *service, double *openBalance);
double deposit(double amount, double *balance, double *service, double *numDeposit, double *amtDeposit);
double check(double amount, double *balance, double *service, double *numCheck, double *amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double);
// ----------------------------

// Main Function provided by textbook.
int main(void) {
	char code;
	double amount, service, balance;
	double openBalance, amtDeposit, amtCheck;
	// double closeBalance;
	int numDeposit, numCheck;

	if (!(fpIn = fopen("account.txt", "r"))) {
		printf("account.txt could not be opened for input.");
		fprintf(fpOut, "account.txt could not be opened for input.");
		exit(1);
	}
	if (!(fpOut = fopen("bank-account.txt", "w"))) {
		printf("bank-account.txt could not be opened for output.");
		fprintf(fpOut, "bank-account.txt could not be opened for output.");
		exit(1);
	}

	amount = 0.0;
	service = 0.0;
	balance = 0.0;
	amtCheck = 0.0;
	amtDeposit = 0.0;
	openBalance = 0.0;
	closeBalance = 0.0;
	numCheck = 0;
	numDeposit = 0;

	outputHeaders();

	while (!feof(fpIn)) {
		fscanf(fpIn, "%c %lf\n", &code, &amount);
		if (code == 'I') {
			initialBalance(amount, &balance, &service, &openBalance);
		}
		else if (code == 'D') {
			deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		}
		else {
			check(amount, &balance, &service, &numCheck, &amtCheck);
		}
	}

	//closeBalance = balance - service;
	//outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);

	fclose(fpIn);
	fclose(fpOut);
	getchar();
	getchar();
	return 0;
}

//-----------------------------------------------------------
void outputHeaders(void) {
	printf("%-20s%30s%30s%30s\n", "Transaction", "Deposit", "Check", "Balance");
	fprintf(fpOut, "%-20s%30s%30s%30s\n", "Transaction", "Deposit", "Check", "Balance");

	for (int i = 1; i <= 120; i++) {
		printf("%c", '-');
		fprintf(fpOut, "%c", '-');
	}
}

double initialBalance(double amount, double *balance, double *service, double *openBalance) {
	*balance = amount;
	*openBalance = amount;
	*service += 3.00;
	printf("\n%-20s%90.2lf", "Initial Balance", *balance);
	fprintf(fpOut, "\n%-20s%90.2lf", "Initial Balance", *balance);
	return *openBalance;
}

double deposit(double amount, double *balance, double *service, double *numDeposit, double *amtDeposit) {
	*balance += amount;
	*numDeposit++;
	*service += 0.03;
	printf("\n%-20s%30.2lf%60.2lf", "Deposit", amount, *balance);
	fprintf(fpOut, "\n%-20s%30.2lf%60.2lf", "Deposit", amount, *balance);
	*amtDeposit += amount;
	return *amtDeposit;
}

double check(double amount, double *balance, double *service, double *numCheck, double *amtCheck) {
	*balance -= amount;
	*numCheck++;
	if (balance < 0) {
		*service += 5.00 + 0.06; // $5.00 overdraft charge and $0.03 for each check cashed
	}
	else {
		*service += 0.06;
	}
	printf("\n%-20s%60.2lf%30.2lf", "Check", amount, *balance);
	fprintf(fpOut, "\n%-20s%60.2lf%30.2lf", "Check", amount, *balance);
	*amtCheck += amount;

	return *amtCheck;
}

void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance) {
	printf("\n%50s", "Bank Statement for the Month");
	fprintf(fpOut, "\n%50s", "Bank Statement for the Month");

	printf("%30s%d", "Total Number of Deposits: ", numDeposit);
	fprintf(fpOut, "%30s%d", "Total Number of Deposits: ", numDeposit);

	printf("%30s%d", "Total Deposit Amount: ", amtDeposit);
	fprintf(fpOut, "%30s%d", "Total Deposit Amount: ", amtDeposit);

	printf("%30s%d", "Total Number of Checks: ", numCheck);
	fprintf(fpOut, "%30s%d", "Total Number of Checks: ", numCheck);

	printf("%30s%d", "Total Service Charge: ", service);
	fprintf(fpOut, "%30s%d", "Total Service Charge: ", service);
}
