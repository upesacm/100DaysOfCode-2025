#include <stdio.h>

int bitLength(int n) {
    int length = 0;
    while (n > 0) {
        length++;
        n >>= 1;
    }
    return length;
}

int isBinaryPalindrome(int n) {
    int left, right;
    int len = bitLength(n);

    for (left = 0, right = len - 1; left < right; left++, right--) {
        // Compare bits at positions left and right
        int bitLeft = (n >> left) & 1;
        int bitRight = (n >> right) & 1;
        if (bitLeft != bitRight)
            return 0;  // Not a palindrome
    }
    return 1;  
}

int main() {
    int n1 = 9;   // binary: 1001
    int n2 = 10;  // binary: 1010

    printf("Input: %d, Output: %s\n", n1, isBinaryPalindrome(n1) ? "Yes" : "No");
    printf("Input: %d, Output: %s\n", n2, isBinaryPalindrome(n2) ? "Yes" : "No");

    return 0;
}
