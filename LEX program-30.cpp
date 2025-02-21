/* Write a LEX program to recognise numbers and words in a statement. Pooja is a small 
girl of age 3 always fond of games. Due to the pandemic, she was not allowed to play 
outside. So her mother designs a gaming event by showing a flash card. Pooja has to 
separate the numbers in one list and words in another list shown in the flash card.*/
%{
#include <stdio.h>
%}
NUMBER   [0-9]+
WORD     [a-zA-Z]+
WHITESPACE [ \t\n]+

%%
{NUMBER}   { printf("Number: %s\n", yytext); }
{WORD}     { printf("Word: %s\n", yytext); }
{WHITESPACE} {/* Ignore whitespace */}
.          { printf("Unknown Token: %s\n", yytext); }
%%

int main() {
    printf("Enter a statement:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
