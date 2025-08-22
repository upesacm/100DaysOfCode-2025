
#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0;

    int count = 0;
    int product = 1;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        product *= nums[right];

        while (product >= k) {
            product /= nums[left];
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int main() {
    int nums[] = {10, 5, 2, 6};
    int k = 100;
    int result = numSubarrayProductLessThanK(nums, sizeof(nums) / sizeof(nums[0]), k);
    printf("%d\n", result);
    return 0;
}
