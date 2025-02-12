#include <stdio.h>
#include <ctype.h>
#include <string.h>
void analyzeToken(char *token) {
    if (token[0] == '\0') return;
    if (isalpha(token[0]) || token[0] == '_') printf("Identifier: %s\n", token);
    else if (isdigit(token[0])) printf("Constant: %s\n", token);
    else printf("Operator: %s\n", token);
}
int main() {
    char ch, token[30];
    int index = 0, inComment = 0;
    
    while ((ch = getchar()) != EOF) {
        if (inComment) {
            if (ch == '*' && (ch = getchar()) == '/') inComment = 0;
            continue;
        }
        
        if (ch == '/' && (ch = getchar()) == '/') {
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        
        if (ch == '/' && (ch = getchar()) == '*') {
            inComment = 1;
            continue;
        }
        
        if (isspace(ch) || ispunct(ch)) {
            token[index] = '\0';
            analyzeToken(token);
            index = 0;
            if (ispunct(ch) && ch != '/') printf("Operator: %c\n", ch);
        } else {
            token[index++] = ch;
        }
    }
    token[index] = '\0';
    analyzeToken(token);
    return 0;
}
