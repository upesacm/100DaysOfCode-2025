#include <stdio.h>

int lengthOfLIS(int arr[], int n) {
    int dp[n];  // dp[i] = LIS ending at index i
    int maxLen = 1;

    // Each element is LIS of length 1 by itself
    for (int i = 0; i < n; i++) dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }

    return maxLen;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of LIS: %d\n", lengthOfLIS(arr, n));
    return 0;
}
