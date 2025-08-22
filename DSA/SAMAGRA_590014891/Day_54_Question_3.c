#include <stdio.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0;

    int left = 0;
    long long prod = 1;
    int count = 0;

    for (int right = 0; right < numsSize; right++) {
        prod *= nums[right];
        while (prod >= k) {
            prod /= nums[left];
            left++;
        }
        count += (right - left + 1);
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
