#include <stdio.h>

int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

int main() {
    int n = 5;
    int i = 2;

    int result = toggleBit(n, i);
    printf("Result after toggling %d-th bit of %d: %d\n", i, n, result);

    return 0;
}
