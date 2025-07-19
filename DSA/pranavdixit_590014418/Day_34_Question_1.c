#include <stdio.h>

int addOne(int n) {
    int mask = 1;
    while (n & mask) {
        n ^= mask;
        mask <<= 1;
    }
    n ^= mask;
    return n;
}

int main() {
    int n = 4;
    int result = addOne(n);
    printf("Result: %d\n", result);
    return 0;
}
