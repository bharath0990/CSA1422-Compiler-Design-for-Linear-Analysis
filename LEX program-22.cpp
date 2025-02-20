// Write a LEX program to count the number of comment lines in a given C program and eliminate them and write into another file.
%{
#include <stdio.h>
#include <stdlib.h>
FILE *output;
int comment_count = 0;
%}

%%

// Single-line comments
"//".* { comment_count++; }

/* Multi-line comments */
"/*"([^*]|\*+[^*/])*("*/") { comment_count++; }

.|
    { fprintf(output, "%s", yytext); }

%%

int main() {
    output = fopen("output.c", "w");
    if (!output) {
        perror("Failed to open output file");
        return 1;
    }
    yylex();
    fclose(output);
    printf("Number of comment lines: %d\n", comment_count);
    return 0;
}

int yywrap() {
    return 1;
}
