#include <stdio.h>

int isolateRightmostSetBit(int n) {
    return n & -n;
}

int main() {
    int n1 = 10;
    int n2 = 12;

    printf("Output 1: %d\n", isolateRightmostSetBit(n1));
    printf("Output 2: %d\n", isolateRightmostSetBit(n2));

    return 0;
}

