#include <stdio.h>

int rob(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int dp[n];
    dp[0] = nums[0];
    dp[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];

    for (int i = 2; i < n; i++) {
        int include = nums[i] + dp[i-2];
        int exclude = dp[i-1];
        dp[i] = (include > exclude) ? include : exclude;
    }
    return dp[n-1];
}

int main() {
    int nums[] = {2,7,9,3,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    printf("%d\n", rob(nums, n));
    return 0;
}
