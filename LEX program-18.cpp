%{
#include <stdio.h>
int macro_count = 0;
int header_count = 0;
%}

%%
#define          { macro_count++; }
#include         { header_count++; }
.|\n           { /* Ignore other characters */ }
%% 

int main(int argc, char **argv) {
    yylex();
    printf("Number of Macros: %d\n", macro_count);
    printf("Number of Header Files: %d\n", header_count);
    return 0;
}

