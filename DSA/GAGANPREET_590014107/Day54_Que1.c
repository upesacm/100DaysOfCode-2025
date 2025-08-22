#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void threeSum(int* nums, int numsSize, int*** result, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    *result = (int**)malloc(sizeof(int*) * numsSize);
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                (*result)[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*result)[*returnSize][0] = nums[i];
                (*result)[*returnSize][1] = nums[left];
                (*result)[*returnSize][2] = nums[right];
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int** result;
    int returnSize;

    threeSum(nums, numsSize, &result, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }
    free(result);
    return 0;
}
