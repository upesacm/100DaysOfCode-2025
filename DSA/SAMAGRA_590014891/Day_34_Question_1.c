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
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Result after adding 1: %d\n", addOne(n));
    return 0;
}
