#include <stdio.h>

int turnOffRightmostBit(int n) {
    return n & (n - 1);
}

int main() {
    int n = 10;

    int result = turnOffRightmostBit(n);

    printf("Result: %d\n", result);
    return 0;
}
