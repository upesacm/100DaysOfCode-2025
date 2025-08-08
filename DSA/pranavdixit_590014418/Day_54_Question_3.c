#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int n, int k) {
    if (k <= 1)
        return 0;

    int count = 0, product = 1, left = 0;

    for (int right = 0; right < n; right++) {
        product *= nums[right];

        while (product >= k)
            product /= nums[left++];

        count += right - left + 1;
    }

    return count;
}

int main() {
    int nums[] = {10, 5, 2, 6};
    int k = 100;
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Valid subarrays: %d\n", numSubarrayProductLessThanK(nums, n, k));  // Output: 8
    return 0;
}
