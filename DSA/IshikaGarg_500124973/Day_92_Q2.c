#include <stdio.h>

int climbStairs(int n) {
    if (n == 0) return 1;  // 1 way (stay at start)
    if (n == 1) return 1;

    int dp[n + 1];
    dp[0] = 1;  // base: 1 way to stand at ground
    dp[1] = 1;  // 1 way to reach first step

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // recurrence relation
    }

    return dp[n];
}

int main() {
    int N;
    printf("Enter number of steps: ");
    scanf("%d", &N);

    printf("Ways to climb %d steps = %d\n", N, climbStairs(N));
    return 0;
}

