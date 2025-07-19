#include <stdio.h>
#include <limits.h>

int binary_palindrome(unsigned int n) {
    if (n == 0) return 1;
    
    unsigned int mask = 1 << (sizeof(n)*8 - 1);
    while ((n & mask) == 0) mask >>= 1;
    
    while (mask > 1) {
        if ((n & mask) ? !(n & 1) : (n & 1))
            return 0;
        n >>= 1;
        mask >>= 2;
    }
    return 1;
}

int main() {
    int n;
    
    printf("Enter non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Error: Invalid input\n");
        return 1;
    }

    while (getchar() != '\n');

    printf("%s\n", binary_palindrome(n) ? "Yes" : "No");
    return 0;
}