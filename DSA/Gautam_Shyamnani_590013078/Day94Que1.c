#include <stdio.h>

int lengthOfLIS_n2(int* nums, int numsSize) {
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++)
        dp[i] = 1;  

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for (int i = 0; i < numsSize; i++)
        if (dp[i] > max)
            max = dp[i];

    return max;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("LIS Length (O(n²)): %d\n", lengthOfLIS_n2(arr, size));
    return 0;
}
