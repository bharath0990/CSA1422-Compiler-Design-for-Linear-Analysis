#line_number.l
%{
#include <stdio.h>
int line_number = 1;
%}

%%
\n      { printf("%d: ", line_number++); }
.       { putchar(yytext[0]); }
%% 

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            yyin = file;
            yylex();
            fclose(file);
        } else {
            perror("Error opening file");
        }
    } else {
        yylex();
    }
    return 0;
}

