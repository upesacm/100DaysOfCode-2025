#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to clear (i): ");
    scanf("%d", &i);
    int mask = ~(1 << i);
    int result = n & mask;
    printf("Result after clearing %d-th bit: %d\n", i, result);
    return 0;
}
