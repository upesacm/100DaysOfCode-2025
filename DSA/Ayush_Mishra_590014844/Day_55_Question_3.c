#include <stdio.h>
#include <stdlib.h>

int countBinarySubarrays(int* nums, int n, int goal) {
    int* freq = (int*)calloc(n * 2 + 1, sizeof(int));
    int sum = 0, count = 0;
    freq[n] = 1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        count += freq[sum - goal + n];
        freq[sum + n]++;
    }
    free(freq);
    return count;
}

int main() {
    int n, goal;
    printf("Enter size of binary array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter binary array elements (0 or 1): ");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter goal sum: ");
    scanf("%d", &goal);
    int result = countBinarySubarrays(nums, n, goal);
    printf("Number of binary subarrays with sum %d is: %d\n", goal, result);
    return 0;
}
