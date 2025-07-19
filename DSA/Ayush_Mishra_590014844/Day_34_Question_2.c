#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer to subtract 1 using bitwise operations: ");
    scanf("%d", &n);

    int mask = 1;
    while (!(n & mask)) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;

    printf("Result after subtracting 1: %d\n", n);
    return 0;
}
