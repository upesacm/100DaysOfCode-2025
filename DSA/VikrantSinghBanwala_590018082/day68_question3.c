#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    if (k > 0 && k % 2 == 1) {
        int minIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        nums[minIndex] = -nums[minIndex];
    }

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    int nums1[] = {4, 2, 3};
    int k1 = 1;
    printf("%d\n", maxSumAfterKNegations(nums1, sizeof(nums1) / sizeof(nums1[0]), k1));

    int nums2[] = {3, -1, 0, 2};
    int k2 = 3;
    printf("%d\n", maxSumAfterKNegations(nums2, sizeof(nums2) / sizeof(nums2[0]), k2));

    return 0;
}
