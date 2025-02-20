//Write a LEX Program to convert the substring abc to ABC from the given input string.
%{
#include <stdio.h>
%}

%%

abc { printf("ABC"); }
.   { printf("%s", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
