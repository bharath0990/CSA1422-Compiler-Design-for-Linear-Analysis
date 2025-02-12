#include <stdio.h>
int main() {
    int a, b, c, d, x, y;
    printf("Enter values for a, b, c, and d: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    x = (a * b) + (a * b) + c;
    y = (a * b) + d;
    printf("Before Optimization:\n");
    printf("x = %d, y = %d\n", x, y);
    int temp = a * b; 
    x = temp + temp + c;
    y = temp + d;
    printf("After Optimization:\n");
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
