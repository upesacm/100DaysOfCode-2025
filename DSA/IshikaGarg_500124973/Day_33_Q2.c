#include <stdio.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n1 = 12;
    int n2 = 10;

    printf("Output 1: %d\n", turnOffRightmostSetBit(n1));
    printf("Output 2: %d\n", turnOffRightmostSetBit(n2));

    return 0;
}
