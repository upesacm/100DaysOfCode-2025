
#include <stdio.h>

int canPartition(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    if (totalSum % 2 != 0) {
        return 0; 
    }
    int target = totalSum / 2;
    int dp[target + 1];
    for (int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    dp[0] = 1; 
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[target];
}

int main() {
    int arr1[] = {1, 2, 3, 5};
    printf("%s\n", canPartition(arr1, sizeof(arr1) / sizeof(arr1[0])) ? "true" : "false");

    int arr2[] = {1, 5, 11, 5};
    printf("%s\n", canPartition(arr2, sizeof(arr2) / sizeof(arr2[0])) ? "true" : "false");

    return 0;
}
