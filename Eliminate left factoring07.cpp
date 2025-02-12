#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void findCommonPrefix(char productions[MAX][MAX], int n, char prefix[MAX]) {
    strcpy(prefix, productions[0]);
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && productions[i][j] && prefix[j] == productions[i][j])
            j++;
        prefix[j] = '\0';
    }
}
void eliminateLeftFactoring(char nonTerminal, char productions[MAX][MAX], int n) {
    char prefix[MAX];
    findCommonPrefix(productions, n, prefix);
    if (strlen(prefix) == 0) {
        printf("No left factoring needed.\n");
        return;
    }
    printf("Left Factored Grammar:\n");
    printf("%c -> %s%c'\n", nonTerminal, prefix, nonTerminal);
    printf("%c' -> ", nonTerminal);
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (strncmp(productions[i], prefix, strlen(prefix)) == 0) {
            if (!first)
                printf(" | ");
            printf("%s", productions[i] + strlen(prefix));
            first = 0;
        }
    }
    printf("\n");
}
int main() {
    char nonTerminal;
    char productions[MAX][MAX];
    int n;
    printf("Enter the non-terminal (A-Z): ");
    scanf(" %c", &nonTerminal);
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (one per line, without spaces):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }
    eliminateLeftFactoring(nonTerminal, productions, n);
    return 0;
}
