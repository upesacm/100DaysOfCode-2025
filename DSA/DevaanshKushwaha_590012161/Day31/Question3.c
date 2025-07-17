#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter a number: ");
    scanf("%u", &n);

    unsigned int result = n >> 1;

    printf("Result: %u\n", result);
    return 0;
}
