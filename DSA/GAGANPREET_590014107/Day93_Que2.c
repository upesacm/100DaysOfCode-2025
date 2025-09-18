#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        
        if (current_sum + nums[i] > nums[i])
            current_sum = current_sum + nums[i];
        else
            current_sum = nums[i];

        
        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    return max_sum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = maxSubArray(nums, size);
    printf("Maximum Subarray Sum: %d\n", result);

    return 0;
}
