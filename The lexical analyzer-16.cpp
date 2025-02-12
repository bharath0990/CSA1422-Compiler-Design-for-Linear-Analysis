#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b ? a / b : 0;
        case '^': {
            int result = 1;
            for (int i = 0; i < b; i++) result *= a;
            return result;
        }
    }
    return 0;
}
int evaluate(char *expression) {
    int values[100], valTop = -1;
    char ops[100];
    int opTop = -1;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            int value = 0;
            while (isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            values[++valTop] = value;
            i--;
        } else if (expression[i] == '(') {
            ops[++opTop] = expression[i];
        } else if (expression[i] == ')') {
            while (opTop != -1 && ops[opTop] != '(') {
                int b = values[valTop--];
                int a = values[valTop--];
                char op = ops[opTop--];
                values[++valTop] = applyOperation(a, b, op);
            }
            opTop--;
        } else {
            while (opTop != -1 && precedence(ops[opTop]) >= precedence(expression[i])) {
                int b = values[valTop--];
                int a = values[valTop--];
                char op = ops[opTop--];
                values[++valTop] = applyOperation(a, b, op);
            }
            ops[++opTop] = expression[i];
        }
    }
    while (opTop != -1) {
        int b = values[valTop--];
        int a = values[valTop--];
        char op = ops[opTop--];
        values[++valTop] = applyOperation(a, b, op);
    }
    return values[valTop];
}
int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);
    printf("Result: %d\n", evaluate(expression));
    return 0;
}
