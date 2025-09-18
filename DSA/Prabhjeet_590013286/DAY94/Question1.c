#include <stdio.h>

int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) dp[i] = 1;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for (int i = 0; i < numsSize; i++)
        if (dp[i] > max) max = dp[i];

    return max;
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("LIS Length: %d\n", lengthOfLIS(nums, size));
    return 0;
}
