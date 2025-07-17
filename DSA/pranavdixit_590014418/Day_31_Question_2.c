#include <stdio.h>

int multiplyByTwo(int n) {
    return n << 1;
}

int main() {
    int n1 = 3, n2 = 7;
    printf("Input: %d\nOutput: %d\n", n1, multiplyByTwo(n1));
    printf("Input: %d\nOutput: %d\n", n2, multiplyByTwo(n2));
    return 0;
}

