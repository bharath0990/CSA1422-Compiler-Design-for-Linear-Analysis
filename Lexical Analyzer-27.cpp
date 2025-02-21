/*Implement Lexical Analyzer using LEX or FLEX (Fast Lexical Analyzer).  The 
program should separate the tokens in the given C program and display with 
appropriate caption.*/
%{
#include <stdio.h>
%}
KEYWORD  (int|float|char|double|return|if|else|while|for|do|switch|case|break|continue)
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER    [0-9]+(\.[0-9]+)?
OPERATOR  [\+\-\*/=<>!&|%^]
DELIMITER [;,(){}\[\]]
WHITESPACE [ \t\n]+

%%
{KEYWORD}    { printf("Keyword: %s\n", yytext); }
{IDENTIFIER} { printf("Identifier: %s\n", yytext); }
{NUMBER}     { printf("Number: %s\n", yytext); }
{OPERATOR}   { printf("Operator: %s\n", yytext); }
{DELIMITER}  { printf("Delimiter: %s\n", yytext); }
{WHITESPACE} {/* Ignore whitespace */}
.            { printf("Unknown Token: %s\n", yytext); }
%%

int main() {
    printf("Enter C program text:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
