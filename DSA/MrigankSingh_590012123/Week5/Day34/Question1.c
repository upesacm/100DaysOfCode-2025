#include <stdio.h>

int add_one(int n) {
    int m = 1;
    while (n & m) {
        n ^= m;
        m <<= 1;
    }
    return n ^ m;
}

int main() {
    int n;

    printf("Enter an integer n: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Invalid integer input.\n");
        return 1;
    }

    while (getchar() != '\n');

    int result = add_one(n);

    printf("%d\n", result);

    return 0;
}