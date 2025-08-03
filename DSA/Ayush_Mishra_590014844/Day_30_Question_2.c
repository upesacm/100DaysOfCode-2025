#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to toggle (i): ");
    scanf("%d", &i);
    int result = n ^ (1 << i);
    printf("Result after toggling %d-th bit: %d\n", i, result);
    return 0;
}
