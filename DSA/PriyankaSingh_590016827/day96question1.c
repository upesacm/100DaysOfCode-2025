#include <stdio.h>

// Function to get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using DP
int knapSack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val1[] = {1, 4, 5, 7};
    int wt1[] = {1, 3, 4, 5};
    int W1 = 7, n1 = 4;
    printf("Knapsack Max Value: %d\n", knapSack(W1, wt1, val1, n1)); // Output: 9

    int val2[] = {1, 2, 3};
    int wt2[] = {4, 5, 1};
    int W2 = 4, n2 = 3;
    printf("Knapsack Max Value: %d\n", knapSack(W2, wt2, val2, n2)); // Output: 3

    return 0;
}
