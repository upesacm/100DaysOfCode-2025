#include <stdio.h>

int main() {
    int n, i;

    // Get the integer and bit position from the user
    printf("Enter an integer (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to set (i): ");
    scanf("%d", &i);

    // Use bitwise OR with a mask that has only the i-th bit set
    int updated = n | (1 << i);

    printf("Updated number after setting the %d-th bit: %d\n", i, updated);

    return 0;
}
