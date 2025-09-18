#include <stdio.h>

int climbStairs(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n1 = 3, n2 = 4;

    printf("Ways to climb %d stairs = %d\n", n1, climbStairs(n1));
    printf("Ways to climb %d stairs = %d\n", n2, climbStairs(n2));

    return 0;
}
