#include <stdio.h>

int minCostClimbingStairs(int* cost, int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int a = dp[i-1] + cost[i-1];
        int b = dp[i-2] + cost[i-2];
        dp[i] = a < b ? a : b;
    }
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
