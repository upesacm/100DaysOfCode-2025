#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    int n1 = 8, n2 = 10;

    if (isPowerOfTwo(n1))
        printf("Input: %d\nOutput: Yes\n", n1);
    else
        printf("Input: %d\nOutput: No\n", n1);

    if (isPowerOfTwo(n2))
        printf("Input: %d\nOutput: Yes\n", n2);
    else
        printf("Input: %d\nOutput: No\n", n2);

    return 0;
}
