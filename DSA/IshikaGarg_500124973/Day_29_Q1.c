#include <stdio.h>

void checkParity(int n) {
    if (n & 1) {
        printf("%d is Odd\n", n);
    } else {
        printf("%d is Even\n", n);
    }
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    checkParity(number);

    return 0;
}
