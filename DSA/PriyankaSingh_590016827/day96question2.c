#include <stdio.h>
#include <stdbool.h>

// Function to check if subset with target sum exists
bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    // Initialize: sum 0 is always achievable (empty subset)
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int j = 1; j <= sum; j++) dp[0][j] = false;

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int arr1[] = {3, 34, 4, 12, 5, 2};
    int n1 = 6, sum1 = 9;
    printf("Subset Sum Exists? %s\n", isSubsetSum(arr1, n1, sum1) ? "Yes" : "No"); // Output: Yes

    int arr2[] = {1, 2, 3};
    int n2 = 3, sum2 = 7;
    printf("Subset Sum Exists? %s\n", isSubsetSum(arr2, n2, sum2) ? "Yes" : "No"); // Output: No

    return 0;
}
