#include <stdio.h>

int setBit(int n, int i) {
    int mask = 1 << i; // Create a mask with 1 at the i-th position
    return n | mask;   // Use OR to set the i-th bit
}

int main() {
    int n, i;

    printf("Enter the number: ");
    scanf("%d", &n);

    printf("Enter the bit position to set (0-indexed): ");
    scanf("%d", &i);

    int result = setBit(n, i);

    printf("The new number after setting the %d-th bit of %d is: %d\n", i, n, result);

    return 0;
}
