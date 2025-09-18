#include <stdio.h>

int lengthOfLIS(int* nums, int n) {
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;

    int maxLen = 1;
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
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(nums)/sizeof(nums[0]);

    printf("%d\n", lengthOfLIS(nums, n));
    return 0;
}
