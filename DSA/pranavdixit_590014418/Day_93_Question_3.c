#include <stdio.h>

int maxSubArray(int* nums, int n) {
    int maxSum = nums[0], currSum = nums[0];
    for (int i = 1; i < n; i++) {
        if (currSum < 0) currSum = nums[i];
        else currSum += nums[i];
        if (currSum > maxSum) maxSum = currSum;
    }
    return maxSum;
}

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    printf("%d\n", maxSubArray(nums, n));
    return 0;
}
