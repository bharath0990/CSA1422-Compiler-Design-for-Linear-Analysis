#include <stdio.h>
#include <ctype.h>
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);
    printf("Recognized operators: ");
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isOperator(expr[i])) {
            printf("%c ", expr[i]);
        }
    }
    printf("\n");
    return 0;
}
