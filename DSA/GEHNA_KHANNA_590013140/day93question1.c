#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int rob(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    return dp[n-1];
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("%d\n", rob(nums, n));
    return 0;
}
