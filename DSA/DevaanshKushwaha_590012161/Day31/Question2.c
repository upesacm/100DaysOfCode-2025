#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter a number: ");
    scanf("%u", &n);

    unsigned int result = n << 1; // Multiply by 2 using left shift

    printf("Result: %u\n", result);
    return 0;
}
