#include <stdio.h>
#include <stdbool.h>

// Utility: subset sum checker (same as Problem 2)
bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int j = 1; j <= sum; j++) dp[0][j] = false;

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

// Main function: partition checker
bool canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];

    // Odd total sum → impossible
    if (total % 2 != 0) return false;

    int target = total / 2;
    return isSubsetSum(arr, n, target);
}

int main() {
    int arr1[] = {1, 5, 11, 5};
    int n1 = 4;
    printf("Can Partition? %s\n", canPartition(arr1, n1) ? "Yes" : "No"); // Output: Yes

    int arr2[] = {1, 2, 3, 5};
    int n2 = 4;
    printf("Can Partition? %s\n", canPartition(arr2, n2) ? "Yes" : "No"); // Output: No

    return 0;
}
