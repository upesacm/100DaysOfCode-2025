#include <stdio.h>

int clearBit(int n, int i) {
    int mask = ~(1 << i);

    return n & mask;
}

int main() {
    int n, i;

    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to clear (i): ");
    scanf("%d", &i);

    int result = clearBit(n, i);
    printf("Number after clearing bit %d: %d\n", i, result);

    return 0;
}

