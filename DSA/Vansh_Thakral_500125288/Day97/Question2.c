#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int arr[], int n) {
    int dp[n][n];

    for (int i = 1; i < n; i++) dp[i][i] = 0; // cost of single matrix is 0

    // chain length from 2 to n-1
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Minimum multiplications: %d\n", matrixChainOrder(arr1, n1)); // 18

    int arr2[] = {10, 20, 30};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Minimum multiplications: %d\n", matrixChainOrder(arr2, n2)); // 6000
    return 0;
}

