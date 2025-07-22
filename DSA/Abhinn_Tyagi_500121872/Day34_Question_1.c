#include <stdio.h>

int addOne(int n) {
    int m = 1;

    while (n & m) {
        n = n ^ m;
        m <<= 1;
    }

    n = n ^ m;

    return n;
}

int main() {
    int n;
    printf("Enter a number to add 1: ");
    scanf("%d", &n);

    printf("Output: %d\n", addOne(n));
    return 0;
}
