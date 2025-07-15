#include <stdio.h>

// Function to clear the i-th bit (set it to 0)
int clearBit(int n, int i) {
    int mask = ~(1 << i);
    return n & mask;
}

// Function to toggle the i-th bit (flip its value)
int toggleBit(int n, int i) {
    int mask = 1 << i;
    return n ^ mask;
}

// Function to count the number of set bits (1s) using Brian Kernighan’s Algorithm
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Clears the least significant set bit
        count++;
    }
    return count;
}

int main() {
    // Test cases
    int n1 = 7, i1 = 1;   // For clearBit
    int n2 = 10, i2 = 1;  // For toggleBit
    int n3 = 9;           // For countSetBits

    // Function calls and output
    printf("Clear %d-th bit of %d => %d\n", i1, n1, clearBit(n1, i1));
    printf("Toggle %d-th bit of %d => %d\n", i2, n2, toggleBit(n2, i2));
    printf("Number of set bits in %d => %d\n", n3, countSetBits(n3));

    return 0;
}
