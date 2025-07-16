#include <stdio.h>

int toggleBit(int n, int i) {
    int mask = 1 << i;

    return n ^ mask;
}

int main() {
    int n, i;

    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to toggle (i): ");
    scanf("%d", &i);

    int result = toggleBit(n, i);
    printf("Number after toggling bit %d: %d\n", i, result);

    return 0;
}
