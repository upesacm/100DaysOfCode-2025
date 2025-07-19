#include <stdio.h>

// Function to add 1 using bitwise operations
int addOne(int n) {
    int mask = 1;
    while (n & mask) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}

// Function to subtract 1 using bitwise operations
int subtractOne(int n) {
    int mask = 1;
    while ((n & mask) == 0) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}

// Function to check if binary representation is a palindrome
int isBinaryPalindrome(int n) {
    int left = 0, right = sizeof(int) * 8 - 1;

    while (left < right) {
        // Extract left and right bits
        int leftBit = (n >> left) & 1;
        int rightBit = (n >> right) & 1;

        // If bits don't match, it's not a palindrome
        if (leftBit != rightBit)
            return 0;

        left++;
        right--;
    }
    return 1;
}

// Main function
int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Add 1
    int added = addOne(n);
    printf("After adding 1 using bitwise: %d\n", added);

    // Subtract 1
    int subtracted = subtractOne(n);
    printf("After subtracting 1 using bitwise: %d\n", subtracted);

    // Check for binary palindrome
    if (isBinaryPalindrome(n))
        printf("Binary representation of %d is a palindrome.\n", n);
    else
        printf("Binary representation of %d is not a palindrome.\n", n);

    return 0;
}
