#include <stdio.h>
#include <string.h>
#include <ctype.h>
char tempVar = 'A';
void generateTAC(char *expr) {
    char operator01;
    char operand1, operand2;
    char result[2] = {0};
    int i, len;
    len = strlen(expr);
    for (i = 0; i < len; i++) {
        if (expr[i] == '*' || expr[i] == '/') {
            operator01 = expr[i];
            operand1 = expr[i - 1];
            operand2 = expr[i + 1];
            result[0] = tempVar++;
            printf("%c = %c %c %c\n", result[0], operand1, operator01, operand2);
            expr[i - 1] = result[0];
            memmove(&expr[i], &expr[i + 2], len - i - 1);
            len -= 2;
            expr[len] = '\0';
            i -= 1;
        }
    }
    len = strlen(expr);
    for (i = 0; i < len; i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            operator01 = expr[i];
            operand1 = expr[i - 1];
            operand2 = expr[i + 1];
            result[0] = tempVar++;
            printf("%c = %c %c %c\n", result[0], operand1, operator01, operand2);
            expr[i - 1] = result[0];
            memmove(&expr[i], &expr[i + 2], len - i - 1);
            len -= 2;
            expr[len] = '\0';
            i -= 1;
        }
    }
}
int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%99s", expression);
    generateTAC(expression);
    return 0;
}
