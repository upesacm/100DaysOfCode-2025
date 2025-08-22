#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int largestSumAfterKNegations(int* nums, int n, int k) {
    qsort(nums, n, sizeof(int), cmp);

    for (int i = 0; i < n && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    qsort(nums, n, sizeof(int), cmp);

    if (k % 2 == 1) nums[0] = -nums[0];

    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    return sum;
}

int main() {
    int arr1[] = {4, 2, 3};
    int arr2[] = {3, -1, 0, 2};
    printf("Max Sum: %d\n", largestSumAfterKNegations(arr1, 3, 1)); // 5
    printf("Max Sum: %d\n", largestSumAfterKNegations(arr2, 4, 3)); // 6
    return 0;
}

