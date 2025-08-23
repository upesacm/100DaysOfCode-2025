#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int largestSumAfterKNegations(int nums[], int n, int k) {
    qsort(nums, n, sizeof(int), cmp);

    for (int i=0; i<n && k>0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    qsort(nums, n, sizeof(int), cmp);

    if (k % 2 == 1) nums[0] = -nums[0];

    int sum = 0;
    for (int i=0; i<n; i++) sum += nums[i];
    return sum;
}

int main() {
    int nums1[] = {4, 2, 3};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("%d\n", largestSumAfterKNegations(nums1, n1, 1)); 

    int nums2[] = {3, -1, 0, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%d\n", largestSumAfterKNegations(nums2, n2, 3)); 

    return 0;
}

