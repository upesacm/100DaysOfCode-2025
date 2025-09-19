#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n+1][sum+1];

    // Initialize DP
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;   // sum 0 always achievable
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;  // no elements but sum > 0

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int arr1[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Subset sum (Example 1): %s\n", isSubsetSum(arr1, n1, sum1) ? "Yes" : "No");

    int arr2[] = {1, 2, 3};
    int sum2 = 7;
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Subset sum (Example 2): %s\n", isSubsetSum(arr2, n2, sum2) ? "Yes" : "No");

    return 0;
}

