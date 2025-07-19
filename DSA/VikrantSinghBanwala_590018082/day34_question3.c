#include<stdio.h>
#include<limits.h>
int isBinaryPalindrome(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    int num_bits = sizeof(unsigned int) * CHAR_BIT;
    int left = num_bits - 1;
    int right = 0;
    while (left > right) {
        unsigned int bit_left = (n >> left) & 1;
        unsigned int bit_right = (n >> right) & 1;
        if (bit_left != bit_right) {
            return 0;
        }
        left--;
        right++;
    }
    return 1;
}
int main() {
    unsigned int n = 9;
    printf("Input: n = %u (binary: %u)\n", n, n);
    if (isBinaryPalindrome(n)) {
        printf("Output: Yes\n");
    } else {
        printf("Output: No\n");
    }
    n = 10;
    printf("Input: n = %u (binary: %u)\n", n, n);
    if (isBinaryPalindrome(n)) {
        printf("Output: Yes\n");
    } else {
        printf("Output: No\n");
    }
    n = 5;
    printf("Input: n = %u (binary: %u)\n", n, n);
    if (isBinaryPalindrome(n)) {
        printf("Output: Yes\n");
    } else {
        printf("Output: No\n");
    }
    n = 12;
    printf("Input: n = %u (binary: %u)\n", n, n);
    if (isBinaryPalindrome(n)) {
        printf("Output: Yes\n");
    } else {
        printf("Output: No\n");
    }
    n = 0;
    printf("Input: n = %u (binary: %u)\n", n, n);
    if (isBinaryPalindrome(n)) {
        printf("Output: Yes\n");
    } else {
        printf("Output: No\n");
    }
    return 0;
}