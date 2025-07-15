#include <stdio.h>

int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

int main() {
    int n1 = 10, i1 = 1;
    printf("Output: %d\n", toggleBit(n1, i1));  

    int n2 = 5, i2 = 2;
    printf("Output: %d\n", toggleBit(n2, i2));  

    return 0;
}
