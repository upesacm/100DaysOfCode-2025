#include <stdio.h>

int divideByTwo(int n) {
    return n >> 1;
}

int main() {
    int n1 = 10, n2 = 9;
    printf("Input: %d\nOutput: %d\n", n1, divideByTwo(n1));
    printf("Input: %d\nOutput: %d\n", n2, divideByTwo(n2));
    return 0;
}
