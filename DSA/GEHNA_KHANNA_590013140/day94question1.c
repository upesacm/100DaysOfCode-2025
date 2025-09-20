#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int lengthOfLIS(int* nums, int n) {
    int dp[n], ans = 1;
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] > ans) ans = dp[i];
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("%d\n", lengthOfLIS(nums, n));
    return 0;
}
