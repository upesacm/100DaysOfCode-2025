#include <stdio.h>

int isolateRightmostSetBit(int n) {
    return n & -n;
}

int main() {
    int n1 = 10;
    int n2 = 12;

    printf("Input: %d → Output: %d\n", n1, isolateRightmostSetBit(n1));  // Output: 2
    printf("Input: %d → Output: %d\n", n2, isolateRightmostSetBit(n2));  // Output: 4

    return 0;
}
