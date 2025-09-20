#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (int i = 2; i < numsSize; i++) {
        int rob_current = dp[i - 2] + nums[i];
        int skip_current = dp[i - 1];
        dp[i] = rob_current > skip_current ? rob_current : skip_current;
    }

    return dp[numsSize - 1];
}

int main() {
    int houses1[] = {1, 2, 3, 1};
    int size1 = sizeof(houses1) / sizeof(houses1[0]);
    printf("Max loot (Example 1): %d\n", rob(houses1, size1));  

    int houses2[] = {2, 7, 9, 3, 1};
    int size2 = sizeof(houses2) / sizeof(houses2[0]);
    printf("Max loot (Example 2): %d\n", rob(houses2, size2));  

    return 0;
}
