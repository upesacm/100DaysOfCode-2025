#include <stdio.h>

int numSubarrayProductLessThanK(int *nums, int numsSize, int k) {
    if (k <= 1) return 0;

    int count = 0;
    long long product = 1;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        product *= nums[right];

        while (product >= k && left <= right) {
            product /= nums[left];
            left++;
        }
        count += (right - left + 1); // all subarrays ending at right
    }
    return count;
}

int main() {
    int nums[] = {10, 5, 2, 6};
    int k = 100;
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Number of subarrays with product < %d: %d\n", k, numSubarrayProductLessThanK(nums, n, k));
    return 0;
}

