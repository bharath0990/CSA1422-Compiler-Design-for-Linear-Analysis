/*The Company ABC runs with employees with several departments. The Organization 
manager had all the mobile numbers of employees. Assume that you are the manager 
and need to verify the valid mobile numbers because there may be some invalid 
numbers present. Implement a LEX program to check whether the mobile number is 
valid or not.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
int isValidMobileNumber(char *number) {
    int length = strlen(number);
    if (length != 10) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isdigit(number[i])) {
            return 0;
        }
    }
    if (number[0] < '6' || number[0] > '9') {
        return 0;
    }
    return 1;
}

int main() {
    char mobile[MAX];

    printf("Enter a mobile number: ");
    scanf("%s", mobile);

    if (isValidMobileNumber(mobile)) {
        printf("Valid mobile number: %s\n", mobile);
    } else {
        printf("Invalid mobile number: %s\n", mobile);
    }

    return 0;
}
