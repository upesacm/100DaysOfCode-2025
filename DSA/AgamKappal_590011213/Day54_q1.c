#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void threeSum(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int found = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);
                found = 1;
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    if (!found) printf("[]\n");
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    threeSum(nums, size, target);
    return 0;
}