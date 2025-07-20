#include <stdio.h>

int subtractOne(int n) {
    int m = 1;
    while ((n & m) == 0) {
        n = n ^ m;
        m <<= 1;
    }
    n = n ^ m;
    return n;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Result after subtracting 1: %d\n", subtractOne(n));
    return 0;
}
