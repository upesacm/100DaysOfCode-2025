#include <stdio.h>

int main() {
    int n;

    // Prompting the user for input
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Bitwise check: If LSB is 1, it's odd; if 0, it's even
    if (n & 1)
        printf("Odd\n");
    else
        printf("Even\n");

    return 0;
}
