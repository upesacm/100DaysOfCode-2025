#include <stdio.h>

int fibonacci_optimized(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    printf("Optimized Fibonacci F(%d) = %d\n", N, fibonacci_optimized(N));
    return 0;
}