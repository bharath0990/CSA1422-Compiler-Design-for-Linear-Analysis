//Write a LEX specification count the number of characters, number of lines & number of words.
%{
#include <stdio.h>
int char_count = 0, word_count = 0, line_count = 0;
%}

%%

[^ \t\n]+  { word_count++; char_count += yyleng; }
[ \t]+    { char_count += yyleng; }
\n        { line_count++; char_count++; }
.         { char_count++; }

%%

int main() {
    yylex();
    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);
    return 0;
}

int yywrap() {
    return 1;
}
