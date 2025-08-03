#include <stdio.h>

int clearBit(int n, int i) {
    return n & ~(1 << i);
}

int main() {
    int n = 10;
    int i = 3;
    
    int result = clearBit(n, i);
    printf("Result after clearing %d-th bit of %d: %d\n", i, n, result);
    
    return 0;
}
