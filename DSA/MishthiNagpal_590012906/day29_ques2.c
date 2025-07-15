#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number (n) and bit position (i): ");
    scanf("%d %d", &n, &i);

    int bit = (n >> i) & 1;
    printf("The bit at position %d is: %d\n", i, bit);

    return 0;
}
