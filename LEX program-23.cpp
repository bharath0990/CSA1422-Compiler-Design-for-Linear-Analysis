//Write a LEX program to identify the capital words from the given input.
%{
#include <stdio.h>
%}

%%

[A-Z]+ { printf("Capital Word: %s\n", yytext); }
.      { /* Ignore other characters */ }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

