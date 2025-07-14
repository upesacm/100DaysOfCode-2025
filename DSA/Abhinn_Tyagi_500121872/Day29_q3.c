#include <stdio.h>

int setIthBit(int n, int i) {
    return n | (1 << i);
}

int main() {
    int n = 5, i = 1;
    printf("Input: n = %d, i = %d\nOutput: %d\n", n, i, setIthBit(n, i));

    n = 8, i = 2;
    printf("Input: n = %d, i = %d\nOutput: %d\n", n, i, setIthBit(n, i));

    return 0;
}
