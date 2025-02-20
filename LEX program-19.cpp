{
#include <stdio.h>
}

%%
<[^>]+>   { printf("%s\n", yytext); }
%% 

int main(int argc, char **argv) {
    yylex();
    return 0;
}

