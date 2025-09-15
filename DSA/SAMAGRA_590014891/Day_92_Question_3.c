#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCostClimbingStairs(int* cost, int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);

    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    int cost[n];
    for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
    printf("%d\n", minCostClimbingStairs(cost, n));
    return 0;
}
