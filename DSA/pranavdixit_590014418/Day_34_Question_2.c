#include <stdio.h>

int subtractOne(int n) {
    int mask = 1;
    while (!(n & mask)) {
        n ^= mask;
        mask <<= 1;
    }
    n ^= mask;
    return n;
}

int main() {
    int n = 8;
    int result = subtractOne(n);
    printf("Result: %d\n", result);
    return 0;
}
