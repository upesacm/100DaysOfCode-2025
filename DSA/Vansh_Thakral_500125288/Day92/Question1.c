#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n1 = 5, n2 = 7;

    printf("Fibonacci(%d) = %d\n", n1, fibonacci(n1));
    printf("Fibonacci(%d) = %d\n", n2, fibonacci(n2));

    return 0;
}

