//
//  main.c
//  character-constant-lab
//
//  Created by Michelle Adea on 7/3/18.
//  Copyright © 2018 Michelle Adea. All rights reserved.
/*  Description: Print a table that displays the Char Constant,
    Description and ASCII Value of character escapecodes.
*/
//

//  Remove single line comment below if using program in Windows.
//#define_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *fp;

int main() {
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
    
    fp = fopen("char-constant-lab-mca.txt", "w");
    
    //Prints header of table.
    printf("Char Constant\tDescription\t\t\t\t\t\tValue\n");
    fprintf(fp, "Char Constant\tDescription\t\t\t\t\t\tValue\n");
    
    //Prints each individual line of table for each character constant.
    //Need to determine correct spacing for columns so print in X width.
    printf("\t\'\\n\'\t\tnewline\t\t\t\t\t\t\t%d\n", n_line);
    fprintf(fp, "\t\'\\n\'\t\tnewline\t\t\t\t\t\t\t%d\n", n_line);
    
    printf("\t\'\\t\'\t\thorizontal tab\t\t\t\t\t%d\n", hz_tab);
    fprintf(fp, "\t\'\\t\'\t\thorizontal tab\t\t\t\t\t%d\n", hz_tab);
    
    printf("\t\'\\v\'\t\tvertical tab\t\t\t\t\t%d\n", vt_tab);
    fprintf(fp, "\t\'\\v\'\t\tvertical tab\t\t\t\t\t%d\n", vt_tab);
    
    printf("\t\'\\b\'\t\tbackspace\t\t\t\t\t\t%d\n", b_space);
    fprintf(fp, "\t\'\\b\'\t\tbackspace\t\t\t\t\t\t%d\n", b_space);
    
    printf("\t\'\\r\'\t\tcarriage return\t\t\t\t\t%d\n", c_return);
    fprintf(fp, "\t\'\\r\'\t\tcarriage return\t\t\t\t\t%d\n", c_return);
    
    printf("\t\'\\f\'\t\tform feed\t\t\t\t\t\t%d\n", form_feed);
    fprintf(fp, "\t\'\\f\'\t\tform feed\t\t\t\t\t\t%d\n", form_feed);
    
    printf("\t\'\\\\\'\t\tbackslash\t\t\t\t\t\t%d\n", b_slash);
    fprintf(fp, "\t\'\\\\\'\t\tbackslash\t\t\t\t\t\t%d\n", b_slash);
    
    printf("\t\'\\\'\'\t\tsingle quote (apostrophe)\t\t%d\n", quote1);
    fprintf(fp, "\t\'\\\'\'\t\tsingle quote (apostrophe)\t\t%d\n", quote1);
    
    printf("\t\'\\\"\'\t\tdouble quote\t\t\t\t\t%d\n", quote2);
    fprintf(fp, "\t\'\\\"\'\t\tdouble quote\t\t\t\t\t%d\n", quote2);
    
    printf("\t\'\\0\'\t\tnull\t\t\t\t\t\t\t%d\n", null);
    fprintf(fp, "\t\'\\0\'\t\tnull\t\t\t\t\t\t\t%d\n", null);
    fclose(fp);
    return 0;
}
