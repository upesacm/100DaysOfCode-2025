#include <stdio.h>

int clearBit(int n, int i) {
    return n & ~(1 << i);
}

int main() {
    int n1 = 7, i1 = 1;
    int n2 = 10, i2 = 3;

    printf("clearBit(%d, %d) = %d\n", n1, i1, clearBit(n1, i1)); 
    printf("clearBit(%d, %d) = %d\n", n2, i2, clearBit(n2, i2)); 

    return 0;
}
