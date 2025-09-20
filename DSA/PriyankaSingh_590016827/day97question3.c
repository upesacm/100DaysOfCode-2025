#include <stdio.h>
#include <limits.h>

// Function to compute MCM cost
int matrixChainOrder(int p[], int n) {
    int dp[n][n];

    // Cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++) dp[i][i] = 0;

    // Chain length L
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("MCM cost: %d\n", matrixChainOrder(arr1, n1)); // Output: 18

    int arr2[] = {10, 20, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("MCM cost: %d\n", matrixChainOrder(arr2, n2)); // Output: 6000

    return 0;
}
