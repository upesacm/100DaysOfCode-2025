#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Build table dp[][] bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // no items or no capacity
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int wt1[] = {1, 3, 4, 5};
    int val1[] = {1, 4, 5, 7};
    int W1 = 7;
    int n1 = sizeof(wt1)/sizeof(wt1[0]);

    printf("Maximum value (Example 1): %d\n", knapsack(W1, wt1, val1, n1));

    int wt2[] = {4, 5, 1};
    int val2[] = {1, 2, 3};
    int W2 = 4;
    int n2 = sizeof(wt2)/sizeof(wt2[0]);

    printf("Maximum value (Example 2): %d\n", knapsack(W2, wt2, val2, n2));

    return 0;
}

