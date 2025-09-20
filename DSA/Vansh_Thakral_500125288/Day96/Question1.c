#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Build table dp[n+1][W+1]
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = (val[i-1] + dp[i-1][w - wt[i-1]] > dp[i-1][w])
                           ? val[i-1] + dp[i-1][w - wt[i-1]]
                           : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int wt1[] = {1,3,4,5};
    int val1[] = {1,4,5,7};
    printf("%d\n", knapsack(7, wt1, val1, 4)); // Output: 9

    int wt2[] = {4,5,1};
    int val2[] = {1,2,3};
    printf("%d\n", knapsack(4, wt2, val2, 3)); // Output: 3
    return 0;
}
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)
