#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int maxSubArray(int* nums, int numsSize) {
    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int arr1[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(arr1, 9)); // Output: 6

    int arr2[] = {1};
    printf("%d\n", maxSubArray(arr2, 1)); // Output: 1

    return 0;
}
