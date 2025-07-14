#include <stdio.h>

int getIthBit(int n, int i) {
    return (n >> i) & 1;
}

int main() {
    int n = 5, i = 0;
    printf("Input: n = %d, i = %d\nOutput: %d\n", n, i, getIthBit(n, i));

    n = 5, i = 1;
    printf("Input: n = %d, i = %d\nOutput: %d\n", n, i, getIthBit(n, i));

    return 0;
}
