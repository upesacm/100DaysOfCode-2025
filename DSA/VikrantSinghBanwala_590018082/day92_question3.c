#include <stdio.h>

int minCostClimbingStairs(int* cost, int n) {
    if (n == 0 || n == 1) return 0;

    int dp[n + 1];
    dp[0] = 0;  
    dp[1] = 0;  

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + cost[i - 1] < dp[i - 2] + cost[i - 2]) ?
                 dp[i - 1] + cost[i - 1] : dp[i - 2] + cost[i - 2];
    }

    return dp[n];  
}

int main() {
    int cost[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int n = sizeof(cost) / sizeof(cost[0]);

    int result = minCostClimbingStairs(cost, n);
    printf("Minimum cost to reach the top: %d\n", result);
    return 0;
}