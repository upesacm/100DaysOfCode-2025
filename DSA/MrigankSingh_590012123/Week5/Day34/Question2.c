#include <stdio.h>
#include <limits.h>

int subtract(int n) {
    int m = 1;
    while (n & m) {
        n ^= m;
        m <<= 1;
    }
    return n ^ m;
}

int main() {
    int n;
    
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Invalid integer input.\n");
        return 1;
    }
    
    while (getchar() != '\n');
    
    printf("Result: %d\n", subtract(n));
    
    return 0;
}