#include <stdio.h>

// Function to check if a number is a power of 2
void isPowerOfTwo(int n) {
    if (n > 0 && (n & (n - 1)) == 0)
        printf("%d is a Power of 2\n", n);
    else
        printf("%d is NOT a Power of 2\n", n);
}

// Function to multiply a number by 2 using bitwise operator
int multiplyBy2(int n) {
    return n << 1;
}

// Function to divide a number by 2 using bitwise operator
int divideBy2(int n) {
    return n >> 1;
}

int main() {
    int n1 = 8, n2 = 10;
    int n3 = 3, n4 = 7;
    int n5 = 10, n6 = 9;

    // Task 1: Check if number is power of 2
    isPowerOfTwo(n1);
    isPowerOfTwo(n2);

    // Task 2: Multiply by 2
    printf("%d multiplied by 2 is %d\n", n3, multiplyBy2(n3));
    printf("%d multiplied by 2 is %d\n", n4, multiplyBy2(n4));

    // Task 3: Divide by 2
    printf("%d divided by 2 is %d\n", n5, divideBy2(n5));
    printf("%d divided by 2 is %d\n", n6, divideBy2(n6));

    return 0;
}
