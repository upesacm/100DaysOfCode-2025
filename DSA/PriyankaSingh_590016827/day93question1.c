#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int curr = prev1;

    for (int i = 2; i < numsSize; i++) {
        curr = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {
    int nums1[] = {1, 2, 3, 1};
    printf("%d\n", rob(nums1, 4)); // Output: 4

    int nums2[] = {2, 7, 9, 3, 1};
    printf("%d\n", rob(nums2, 5)); // Output: 12

    return 0;
}
