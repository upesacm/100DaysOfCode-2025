#include <stdio.h>

int subtractOne(int n) {
    int mask = 1;

    // Iterate until we find the first 1-bit
    while ((n & mask) == 0) {
        // Flip 0s to 1s as we borrow
        n = n ^ mask;
        mask <<= 1;
    }

    // Flip the first 1-bit to 0 to complete subtraction
    n = n ^ mask;

    return n;
}

int main() {
    int n1 = 5;
    int n2 = 8;

    printf("Input: %d, Output: %d\n", n1, subtractOne(n1));  
    printf("Input: %d, Output: %d\n", n2, subtractOne(n2));  

    return 0;
}
