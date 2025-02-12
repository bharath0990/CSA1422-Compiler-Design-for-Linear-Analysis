#include <stdio.h>
#include <ctype.h>
#include <string.h>
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline",
    "int", "long", "register", "restrict", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic",
    "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local"
};
int isKeyword(char *str) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
int isValidIdentifier(char *identifier) {
    if (!identifier || !identifier[0]) {
        printf("Identifier cannot be empty.\n");
        return 0;
    }
    if (isKeyword(identifier)) {
        printf("'%s' is a reserved keyword.\n", identifier);
        return 0;
    }
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        printf("Identifier must start with a letter or an underscore.\n");
        return 0;
    }
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            printf("Identifier can only contain letters, digits, and underscores.\n");
            return 0;
        }
    }
    return 1; 
}
int main() {
    char testIdentifiers[][20] = {
        "validIdentifier", "_valid", "123invalid", "valid_123", "invalid-identifier", "for", "while", "anotherValid_1"
    };
    int numTests = sizeof(testIdentifiers) / sizeof(testIdentifiers[0]);

    for (int i = 0; i < numTests; i++) {
        if (isValidIdentifier(testIdentifiers[i]))
            printf("'%s' is a valid identifier.\n", testIdentifiers[i]);
        else
            printf("'%s' is an invalid identifier.\n", testIdentifiers[i]);
    }

    return 0;
} 
