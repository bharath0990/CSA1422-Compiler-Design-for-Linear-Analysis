//Write a LEX Program to check the email address is valid or not.
%{
#include <stdio.h>
%}

%%

[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} { printf("Valid Email: %s\n", yytext); }
.      { /* Ignore other characters */ }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
