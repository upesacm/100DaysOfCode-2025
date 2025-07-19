#include <stdio.h>

int main() {
    int a, b;
    printf("Enter first number (a): ");
    scanf("%d", &a);
    printf("Enter second number (b): ");
    scanf("%d", &b);
    if ((a ^ b) < 0) {
        printf("Output: True (They have opposite signs)\n");
    } else {
        printf("Output: False (They do NOT have opposite signs)\n");
    }
    return 0;
}
