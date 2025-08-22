#include <stdio.h>

int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int maxSum = numsSize;
    int freq[maxSum + 1];
    for (int i = 0; i <= maxSum; i++) freq[i] = 0;

    freq[0] = 1;
    int sum = 0, count = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum - goal >= 0) count += freq[sum - goal];
        freq[sum]++;
    }
    return count;
}

int main() {
    int n, goal;
    printf("Enter array size: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter binary array elements (0 or 1): ");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter goal: ");
    scanf("%d", &goal);
    printf("Count: %d\n", numSubarraysWithSum(nums, n, goal));
    return 0;
}
