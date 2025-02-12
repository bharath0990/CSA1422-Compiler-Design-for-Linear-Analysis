#include <stdio.h>
#include <stdlib.h>
void generateCode(char op, int left, int right) {
    printf("LOAD R1, %d\n", left);
    printf("LOAD R2, %d\n", right);
    switch (op) {
        case '+':
            printf("ADD R1, R2\n");
            break;
        case '-':
            printf("SUB R1, R2\n");
            break;
        case '*':
            printf("MUL R1, R2\n");
            break;
        case '/':
            printf("DIV R1, R2\n");
            break;
        default:
            printf("INVALID OPERATION\n");
            return;
    }
    printf("STORE R1, RESULT\n");
}
int main() {
    char op;
    int left, right;
    printf("Enter an arithmetic operation (e.g., 5 + 3): ");
    scanf("%d %c %d", &left, &op, &right);
    printf("Generated Assembly Code:\n");
    generateCode(op, left, right);
    return 0;
}

