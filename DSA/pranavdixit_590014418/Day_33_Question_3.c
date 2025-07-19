#include <stdio.h>

int isolateRightmostBit(int n) {
    return n & -n;
}

int main() {
    int n = 12;

    int result = isolateRightmostBit(n);

    printf("Rightmost Set Bit: %d\n", result);
    return 0;
}
