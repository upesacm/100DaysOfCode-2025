#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCostClimbingStairs(int* cost, int n) {
    int dp[n + 1];  // dp[i] = min cost to reach step i

    dp[0] = 0;  // starting point
    dp[1] = 0;  // can start from step 0 or 1 for free

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[n];  // min cost to reach top
}

int main() {
    int n;
    printf("Enter number of steps: ");
    scanf("%d", &n);

    int cost[n];
    printf("Enter cost array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    int result = minCostClimbingStairs(cost, n);
    printf("Minimum cost to reach top = %d\n", result);

    return 0;
}

