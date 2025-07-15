#include <stdio.h>

int getIthBit(int n, int i) {
    if ((n & (1 << i)) != 0)
        return 1;
    else
        return 0;
}

int main() {
    int n, i;

    printf("Enter an integer n: ");
    scanf("%d", &n);

    printf("Enter the bit position i (0-indexed from right): ");
    scanf("%d", &i);

    int bit = getIthBit(n, i);
    printf("The %d-th bit of %d is: %d\n", i, n, bit);

    return 0;
}
