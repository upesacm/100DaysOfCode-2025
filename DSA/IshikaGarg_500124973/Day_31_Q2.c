#include <stdio.h>

int multiplyByTwo(int n) {
    return n << 1;
}

int main() {
    int input1 = 3;
    int input2 = 7;
    printf("Input 1: %d\nOutput 1: %d\n", input1, multiplyByTwo(input1));
    printf("Input 2: %d\nOutput 2: %d\n", input2, multiplyByTwo(input2));
    return 0;
}
