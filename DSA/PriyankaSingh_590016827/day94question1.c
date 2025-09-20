#include <stdio.h>

// Function to find LIS length using O(n^2) DP
int lengthOfLIS(int arr[], int n) {
    int dp[n];
    int maxLen = 1;

    // Initialize all LIS values as 1
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    // Compute LIS values in bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen)
            maxLen = dp[i];
    }

    return maxLen;
}

int main() {
    int arr1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("LIS length: %d\n", lengthOfLIS(arr1, n1)); // Output: 4

    int arr2[] = {0, 1, 0, 3, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("LIS length: %d\n", lengthOfLIS(arr2, n2)); // Output: 4

    return 0;
}
