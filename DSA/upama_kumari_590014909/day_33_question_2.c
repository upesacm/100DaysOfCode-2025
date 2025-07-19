#include <stdio.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n = 10;

    int result = turnOffRightmostSetBit(n);
    printf("%d\n", result);

    return 0;
}
