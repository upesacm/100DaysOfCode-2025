#include <stdio.h>

int isolateRightmostSetBit(int n) {
    return n & -n;
}

int main() {
    int n = 12;

    int result = isolateRightmostSetBit(n);
    printf("%d\n", result);  

    return 0;
}
