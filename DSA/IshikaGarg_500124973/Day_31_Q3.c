#include <stdio.h>

int divideByTwo(int n) {
    return n >> 1;
}

int main() {
    int input1 = 10;
    int input2 = 9;
    printf("Input 1: %d\nOutput 1: %d\n", input1, divideByTwo(input1));
    printf("Input 2: %d\nOutput 2: %d\n", input2, divideByTwo(input2));
    return 0;
}

