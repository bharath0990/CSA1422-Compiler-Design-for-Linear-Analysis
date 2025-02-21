/*Keywords are predefined, reserved words used in programming that have special 
meanings to the compiler. Keywords are part of the syntax and they cannot be used as 
an identifier. In general there are 32 keywords. The prime function of Lexical 
Analyser is token Generation. Among the 6 types of tokens, differentiating Keyword 
and Identifier is a challenging issue. Thus write a LEX program to separate keywords 
and identifiers.*/
%{
#include <stdio.h>
#include <string.h>
%}
KEYWORD  (auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+

%%
{KEYWORD}    { printf("Keyword: %s\n", yytext); }
{IDENTIFIER} { printf("Identifier: %s\n", yytext); }
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
