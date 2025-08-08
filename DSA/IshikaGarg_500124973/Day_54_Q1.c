#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void threeSum(int *nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate first elements
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);

                // skip duplicates for left
                while (left < right && nums[left] == nums[left + 1]) left++;
                // skip duplicates for right
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    printf("Unique triplets summing to %d:\n", target);
    threeSum(nums, n, target);

    return 0;
}

