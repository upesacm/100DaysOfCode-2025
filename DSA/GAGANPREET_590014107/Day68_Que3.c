#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int largestSumAfterKNegations(int* nums, int numsSize, int k) {

    qsort(nums, numsSize, sizeof(int), cmp);

    
    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    
    int min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
    }

    if (k % 2 == 1)
        min = -min;

    
    int sum = 0;
    int flipped = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == min && !flipped && k % 2 == 1) {
            sum += -nums[i];
            flipped = 1;
        } else {
            sum += nums[i];
        }
    }

    return sum;
}

int main() {
    int nums1[] = {4, 2, 3};
    int k1 = 1;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Max sum (Example 1): %d\n", largestSumAfterKNegations(nums1, size1, k1)); 

    int nums2[] = {3, -1, 0, 2};
    int k2 = 3;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Max sum (Example 2): %d\n", largestSumAfterKNegations(nums2, size2, k2));  

    return 0;
}
