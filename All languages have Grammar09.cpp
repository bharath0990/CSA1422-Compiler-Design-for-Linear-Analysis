#include <stdio.h>
#include <ctype.h>

int isValidGrammar(char *str) {
    if (!isalpha(str[0])) {
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isValidGrammar(input)) {
        printf("The string satisfies the grammar.\n");
    } else {
        printf("The string does not satisfy the grammar.\n");
    }
    return 0;
}

