#include <stdio.h>

int minCostClimbingStairs(int* cost, int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        int oneStep = dp[i-1] + cost[i-1];
        int twoStep = dp[i-2] + cost[i-2];
        dp[i] = (oneStep < twoStep) ? oneStep : twoStep;
    }
    return dp[n];
}

int main() {
    int cost[] = {1,100,1,1,1,100,1,1,100,1};
    int n = sizeof(cost)/sizeof(cost[0]);

    printf("%d\n", minCostClimbingStairs(cost, n));
    return 0;
}
