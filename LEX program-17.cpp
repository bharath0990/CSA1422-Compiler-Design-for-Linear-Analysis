%{
#include <stdio.h>
%}

%%
[0-9]+(\.[0-9]+)?   { printf("Constant: %s\n", yytext); }
#define            { /* Ignore preprocessor directives */ }
#include            { /* Ignore include directives */ }
[ \t\n]+          { /* Ignore whitespace */ }
.                 { /* Ignore other characters */ }
%% 

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            yyin = file;
            yylex();
            fclose(file);
        } else {
            printf("Error opening file: %s\n", argv[1]);
        }
    } else {
        printf("Usage: %s <source_file>\n", argv[0]);
    }
    return 0;
}

