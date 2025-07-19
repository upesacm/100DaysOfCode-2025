#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int m = 1;
    printf("Initial n = %d\n", n);
    while (n & m) {
        printf("n & m = %d (both bits are 1, flipping and propagating carry)\n", n & m);
        n = n ^ m;
        printf("After XOR, n = %d\n", n);
        m = m << 1;
        printf("Carry moved left, m = %d\n", m);
    }
    n = n ^ m;
    printf("Final XOR sets the carry bit, n = %d\n", n);
    printf("Result after adding 1: %d\n", n);
    return 0;
}
