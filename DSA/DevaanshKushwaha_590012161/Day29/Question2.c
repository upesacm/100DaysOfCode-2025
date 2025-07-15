#include <stdio.h>

int main() {
    int n, i;

    printf("Enter an integer (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to check (i): ");
    scanf("%d", &i);

    // Right shift the number i times and mask with 1
    int bit = (n >> i) & 1;

    printf("The %d-th bit of %d is: %d\n", i, n, bit);

    return 0;
}
