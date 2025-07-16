#include <stdio.h>

int main() {
    int n, i;
    printf("Enter a number (n): ");
    scanf("%d", &n);
    printf("Enter bit position to toggle (i): ");
    scanf("%d", &i);

    int result = n ^ (1 << i);
    printf("New number after toggling %d-th bit: %d\n", i, result);

    return 0;
}
