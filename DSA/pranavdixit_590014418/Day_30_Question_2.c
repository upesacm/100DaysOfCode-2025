#include <stdio.h>

int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

int main() {
    int n1 = 10, i1 = 1;
    int result1 = toggleBit(n1, i1);
    printf("toggleBit(%d, %d) = %d\n", n1, i1, result1); // Output: 8

    int n2 = 5, i2 = 2;
    int result2 = toggleBit(n2, i2);
    printf("toggleBit(%d, %d) = %d\n", n2, i2, result2); // Output: 1

    return 0;
}
