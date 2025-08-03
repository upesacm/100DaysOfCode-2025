#include <stdio.h>

const char* isPowerOfTwo(int n) {
    return (n > 0 && (n & (n - 1)) == 0) ? "Yes" : "No";
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("Output: %s\n", isPowerOfTwo(n));

    return 0;
}
