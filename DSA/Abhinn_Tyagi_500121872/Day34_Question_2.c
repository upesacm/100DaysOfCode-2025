#include <stdio.h>

int subtractOne(int n) {
    int m = 1;

    while (!(n & m)) {
        n = n ^ m;
        m <<= 1;
    }

    n = n ^ m;

    return n;
}

int main() {
    int n;
    printf("Enter a number to subtract 1: ");
    scanf("%d", &n);

    printf("Output: %d\n", subtractOne(n));
    return 0;
}
