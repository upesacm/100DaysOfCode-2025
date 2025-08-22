#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int n, int k) {
    if (k <= 1) return 0;

    int count = 0, left = 0;
    long long product = 1;

    for (int right = 0; right < n; right++) {
        product *= nums[right];

        while (product >= k && left <= right) {
            product /= nums[left++];
        }

        count += right - left + 1;
    }

    return count;
}

int main() {
    int nums[] = {10, 5, 2, 6};
    int k = 100;
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", numSubarrayProductLessThanK(nums, n, k)); 
    return 0;
}

