#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_RULES 10
#define MAX_LENGTH 100
void eliminateLeftRecursion(char nonTerminal, char productions[MAX_RULES][MAX_LENGTH], int prodCount) {
    char alpha[MAX_RULES][MAX_LENGTH], beta[MAX_RULES][MAX_LENGTH];
    int alphaCount = 0, betaCount = 0;
    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == nonTerminal) {
            strcpy(alpha[alphaCount], productions[i] + 1);
            alphaCount++;
        } else {
            strcpy(beta[betaCount], productions[i]);
            betaCount++;
        }
    }
    if (alphaCount == 0) {
        printf("%c ->", nonTerminal);
        for (int i = 0; i < prodCount; i++) {
            if (i > 0) printf(" | ");
            printf(" %s", productions[i]);
        }
        printf("\n");
        return;
    } 
    char newNonTerminal[3] = {nonTerminal, '\'', '\0'};
    printf("%c ->", nonTerminal);
    for (int i = 0; i < betaCount; i++) {
        if (i > 0) printf(" | ");
        printf(" %s%s", beta[i], newNonTerminal);
    }
    printf("\n");
    printf("%s ->", newNonTerminal);
    for (int i = 0; i < alphaCount; i++) {
        if (i > 0) printf(" | ");
        printf(" %s%s", alpha[i], newNonTerminal);
    }
    printf(" | e\n");
}
int main() {
    char nonTerminal;
    int prodCount;
    char productions[MAX_RULES][MAX_LENGTH];
    
    printf("Enter the non-terminal: ");
    scanf(" %c", &nonTerminal);
    
    printf("Enter the number of productions: ");
    scanf("%d", &prodCount);
    getchar();
    
    printf("Enter the productions for %c (one per line, without spaces, use '|' for OR):\n", nonTerminal);
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", productions[i]);
    }
    eliminateLeftRecursion(nonTerminal, productions, prodCount);
    
    return 0;
}
