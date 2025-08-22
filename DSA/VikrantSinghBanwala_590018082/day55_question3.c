#include <stdio.h>
#include <stdlib.h>

int numSubarraysWithSum(int* nums, int n, int goal) {
    int count = 0;
    int currentSum = 0;
    int* prefixSumCount = (int*)calloc(n + 1, sizeof(int));
    prefixSumCount[0] = 1;

    for (int i = 0; i < n; i++) {
        currentSum += nums[i];

        if (currentSum >= goal) {
            count += prefixSumCount[currentSum - goal];
        }

        prefixSumCount[currentSum]++;
    }

    free(prefixSumCount);
    return count;
}

int main() {
    int nums1[] = {1, 0, 1, 0, 1};
    int goal1 = 2;
    printf("%d\n", numSubarraysWithSum(nums1, 5, goal1));

    int nums2[] = {0, 0, 0, 0, 0};
    int goal2 = 0;
    printf("%d\n", numSubarraysWithSum(nums2, 5, goal2));

    return 0;
}
