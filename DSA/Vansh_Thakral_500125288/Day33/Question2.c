#include <stdio.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n1 = 12;
    int n2 = 10;

    printf("Input: %d → Output: %d\n", n1, turnOffRightmostSetBit(n1));  // Output: 8
    printf("Input: %d → Output: %d\n", n2, turnOffRightmostSetBit(n2));  // Output: 8

    return 0;
}
