//Description: Solving for a quadratic formula.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

FILE *fp;

int main(){
	double a, b, c, x1, x2;
	double temp;

	fp = fopen("quadratic-formula.txt", "w");

	//Values for 3 coefficients.
	printf("Enter value for a=");
	scanf("%lf", &a);
	fprintf(fp, "The user entered for a=%lf\n", a);
	printf("Enter value for b=");
	scanf("%lf", &b);
	fprintf(fp, "The user entered for b=%lf\n", b);
	printf("Enter value for c=");
	scanf("%lf", &c);
	fprintf(fp, "The user entered for c=%lf\n", c);

	temp = b * b - 4 * a * c;

	//Checking if temp (temporary vaariable) is negative number.
	if (temp < 0) {
		printf("Only complex solution exists\n");
		fprintf(fp, "Only complex solution exists\n");
		getchar();
		fclose(fp);
		return -1;
	}

	x1 = (-b + sqrt(temp)) / (2 * a);
	x2 = (-b - sqrt(temp)) / (2 * a);

	printf("x1=%lf\n", x1);
	fprintf(fp, "x1 = %lf\n", x1);
	printf("x2=%lf\n", x2);
	fprintf(fp, "x2 = %lf\n", x2);
		
	getchar();
	fclose(fp);
	return -1;
}
