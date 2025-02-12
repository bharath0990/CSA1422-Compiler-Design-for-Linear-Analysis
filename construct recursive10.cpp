#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[100];
int pos = 0;
void E();
void E_prime();
void T();
void T_prime();
void F();
void error() {
    printf("Error in parsing\n");
    exit(1);
}
void match(char expected) {
    if (input[pos] == expected) {
        pos++;
    } else {
        error();
    }
}
void E() {
    T();
    E_prime();
}
void E_prime() {
    if (input[pos] == '+') {
        match('+');
        T();
        E_prime();
    }
}
void T() {
    F();
    T_prime();
}
void T_prime() {
    if (input[pos] == '*') {
        match('*');
        F();
        T_prime();
    }
}
void F() {
    if (input[pos] == '(') {
        match('(');
        E();
        match(')');
    } else if (input[pos] >= 'a' && input[pos] <= 'z') {
        match(input[pos]);
    } else {
        error();
    }
}
int main() {
    printf("Enter an expression: ");
    scanf("%s", input);
    E();
    if (input[pos] == '\0') {
        printf("Parsing successful\n");
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}
