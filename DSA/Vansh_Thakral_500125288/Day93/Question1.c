#include <stdio.h>

int rob(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int dp[n];
    dp[0] = nums[0];
    dp[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];

    for (int i = 2; i < n; i++) {
        int rob = nums[i] + dp[i-2];   // rob current house
        int skip = dp[i-1];            // skip current house
        dp[i] = (rob > skip) ? rob : skip;
    }
    return dp[n-1];
}

int main() {
    int houses1[] = {1,2,3,1};
    int n1 = sizeof(houses1)/sizeof(houses1[0]);
    printf("Max Robbery = %d\n", rob(houses1, n1)); // Output: 4

    int houses2[] = {2,7,9,3,1};
    int n2 = sizeof(houses2)/sizeof(houses2[0]);
    printf("Max Robbery = %d\n", rob(houses2, n2)); // Output: 12
    return 0;
}

