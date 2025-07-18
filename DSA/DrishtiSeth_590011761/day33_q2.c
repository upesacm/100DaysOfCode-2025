
#include <stdio.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n1 = 12;
    printf("%d\n", turnOffRightmostSetBit(n1));  // Output: 8

    int n2 = 10;
    printf("%d\n", turnOffRightmostSetBit(n2));  // Output: 8

    return 0;
}
