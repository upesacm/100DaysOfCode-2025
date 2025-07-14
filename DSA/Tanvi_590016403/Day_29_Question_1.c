#include <stdio.h>

// Function 1: Check if a number is Even or Odd using Bit Manipulation
void checkEvenOdd(int n) {
    if (n & 1)
        printf("%d is Odd\n", n);
    else
        printf("%d is Even\n", n);
}

// Function 2: Get the i-th Bit of a Number (0-indexed from right)
int getIthBit(int n, int i) {
    int mask = 1 << i;
    return (n & mask) ? 1 : 0;
}

// Function 3: Set the i-th Bit of a Number (0-indexed from right)
int setIthBit(int n, int i) {
    int mask = 1 << i;
    return (n | mask);
}

// Main function to test all functionalities
int main() {
    int n, i;

    // Example 1: Check Even/Odd
    printf("Enter a number to check even or odd: ");
    scanf("%d", &n);
    checkEvenOdd(n);

    // Example 2: Get i-th Bit
    printf("\nEnter number and bit position to check (e.g., n i): ");
    scanf("%d %d", &n, &i);
    printf("The %d-th bit of %d is: %d\n", i, n, getIthBit(n, i));

    // Example 3: Set i-th Bit
    printf("\nEnter number and bit position to set (e.g., n i): ");
    scanf("%d %d", &n, &i);
    int result = setIthBit(n, i);
    printf("The number after setting the %d-th bit is: %d\n", i, result);

    return 0;
}
