#include <stdio.h>
int main() {
    int ch;
    int whitespace_count = 0, newline_count = 0;
    printf("Enter text (Type '#' to end input):\n");
    while ((ch = getchar()) != '#') {  
        if (ch == ' ' || ch == '\t') {
            whitespace_count++;
        } else if (ch == '\n') {
            newline_count++;
        }
    }
    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);
    return 0;
}
