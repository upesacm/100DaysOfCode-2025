#include <stdio.h>

const char* isPowerOfTwo(int n) {
    if (n > 0 && (n & (n - 1)) == 0)
        return "Yes";
    else
        return "No";
}

int main() {
    int input1 = 8;
    int input2 = 10;
    printf("Input 1: %d\nOutput 1: %s\n", input1, isPowerOfTwo(input1));
    printf("Input 2: %d\nOutput 2: %s\n", input2, isPowerOfTwo(input2));
    return 0;
}
