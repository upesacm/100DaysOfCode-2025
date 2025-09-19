#include <stdio.h>
#include <stdbool.h>

bool canPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0) return false; // odd sum can't be partitioned

    int target = sum / 2;
    bool dp[n+1][target+1];

    // Initialize DP
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int j = 1; j <= target; j++)
        dp[0][j] = false;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][target];
}

int main() {
    int arr1[] = {1, 5, 11, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Partition (Example 1): %s\n", canPartition(arr1, n1) ? "Yes" : "No");

    int arr2[] = {1, 2, 3, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Partition (Example 2): %s\n", canPartition(arr2, n2) ? "Yes" : "No");

    return 0;
}

