#include <stdio.h>

int addOne(int n) {
    int mask = 1;

    // Iterate until there is no carry
    while (n & mask) {
        // Flip the current bit
        n = n ^ mask;

        // Move to the next bit
        mask <<= 1;
    }

    // Set the first zero bit
    n = n ^ mask;

    return n;
}

int main() {
    int n1 = 4;
    int n2 = 7;

    printf("Input: %d, Output: %d\n", n1, addOne(n1)); 
    printf("Input: %d, Output: %d\n", n2, addOne(n2));  

    return 0;
}

