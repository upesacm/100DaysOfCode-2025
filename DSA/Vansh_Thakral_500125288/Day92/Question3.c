#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }

int minCostClimbingStairs(int cost[], int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;

    int dp[n];
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int main() {
    int cost1[] = {10, 15, 20};
    int n1 = 3;
    int cost2[] = {1,100,1,1,1,100,1,1,100,1};
    int n2 = 10;

    printf("Min cost (example 1) = %d\n", minCostClimbingStairs(cost1, n1));
    printf("Min cost (example 2) = %d\n", minCostClimbingStairs(cost2, n2));

    return 0;
}

