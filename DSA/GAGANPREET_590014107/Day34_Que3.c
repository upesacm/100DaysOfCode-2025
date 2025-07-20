#include <stdio.h>

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n >>= 1;
    }
    return count;
}

int isBinaryPalindrome(int n) {
    int bitCount = countBits(n);

    for (int i = 0; i < bitCount / 2; i++) {
        int leftBit = (n >> (bitCount - 1 - i)) & 1;
        int rightBit = (n >> i) & 1;
        if (leftBit != rightBit)
            return 0; 
    }
    return 1;  
}

int main() {
    int n;

    n = 9;  
    printf("Input: %d\n", n);
    printf("Output: %s\n", isBinaryPalindrome(n) ? "Yes" : "No");

    n = 10;  
    printf("Input: %d\n", n);
    printf("Output: %s\n", isBinaryPalindrome(n) ? "Yes" : "No");


    return 0;
}
