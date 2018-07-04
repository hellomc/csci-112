/* Author: Michelle Adea
Date: 2018 July 3
Description: Print a table that displays the Char Constant,
Description, and ASCII Value of escape characters.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int main(){
	//Character Constants assigned to variables.
	int n_line = '\n';
	int hz_tab = '\t';
	int vt_tab = '\v';
	int b_space = '\b';
	int c_return = '\r';
	int form_feed = '\f';
	int b_slash = '\\';
	int quote1 = '\'';
	int quote2 = '\"';
	int null = '\0';

	fp = fopen("char-constant-mca.txt", "w");

	//Prints header of table.
	//(-) makes contents of table left-justified.
	printf("%-15s%-30s%-10s\n", "Char Constant", "Description", "Value");
	fprintf(fp, "%-15s%-30s%-10s\n", "Char Constant", "Description", "Value");

	//Prints each individual line of table for each character constant.
	printf("%-15s%-30s%-10d\n", "\'\\n\'", "newline", n_line);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\n\'", "newline", n_line);

	printf("%-15s%-30s%-10d\n", "\'\\t\'", "horizontal tab", hz_tab);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\t\'", "horizontal tab", hz_tab);

	printf("%-15s%-30s%-10d\n", "\'\\v\'", "vertical tab", vt_tab);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\v\'", "vertical tab", vt_tab);

	printf("%-15s%-30s%-10d\n", "\'\\b\'", "backspace", b_space);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\b\'", "backspace", b_space);

	printf("%-15s%-30s%-10d\n", "\'\\r\'", "carriage return", c_return);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\r\'", "carriage return", c_return);

	printf("%-15s%-30s%-10d\n", "\'\\f\'", "form feed", form_feed);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\f\'", "form feed", form_feed);

	printf("%-15s%-30s%-10d\n", "\'\\\\\'", "backslash", b_slash);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\\\\'", "backslash", b_slash);

	printf("%-15s%-30s%-10d\n", "\'\\\'\'", "single quote (apostrophe)", quote1);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\\'\'", "single quote (apostrophe)", quote1);

	printf("%-15s%-30s%-10d\n", "\'\\\"\'", "double quote", quote2);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\\"\'", "double quote", quote2);

	printf("%-15s%-30s%-10d\n", "\'\\0\'", "null", null);
	fprintf(fp, "%-15s%-30s%-10d\n", "\'\\0\'", "null", null);

	fclose(fp);
	getchar();
	return 0;
}
