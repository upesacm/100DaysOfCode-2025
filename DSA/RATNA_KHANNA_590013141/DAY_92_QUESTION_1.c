#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. N must be non-negative.\n");
        return 0;
    }

    long long fib[n + 1];
    fib[0] = 0;
    if (n > 0) fib[1] = 1;

    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("The %dth Fibonacci number is: %lld\n", n, fib[n]);
    return 0;
}
