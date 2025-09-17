#include <stdio.h>

// Function to find LIS length
int lengthOfLIS(int* nums, int n) {
    if (n == 0) return 0;
    int dp[n];
    int maxLen = 1;

    for (int i = 0; i < n; i++) dp[i] = 1; // each element alone is LIS

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }
    return maxLen;
}

int main() {
    int arr1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("LIS Length = %d\n", lengthOfLIS(arr1, n1)); // Output: 4

    int arr2[] = {0, 1, 0, 3, 2, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("LIS Length = %d\n", lengthOfLIS(arr2, n2)); // Output: 4
    return 0;
}
