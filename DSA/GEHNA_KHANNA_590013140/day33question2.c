#include <stdio.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    int result = turnOffRightmostSetBit(n);
    printf("Result after turning off the rightmost set bit: %d\n", result);

    return 0;
}
