#include <stdio.h>
#include <stdlib.h>

int numSubarraysWithSum(int *nums, int n, int goal) {
    int prefix_sum = 0, count = 0;
    int *freq = calloc(n + 1, sizeof(int)); // store frequency of prefix sums

    freq[0] = 1; // prefix sum = 0 initially

    for (int i = 0; i < n; i++) {
        prefix_sum += nums[i];
        if (prefix_sum - goal >= 0 && prefix_sum - goal <= n) {
            count += freq[prefix_sum - goal];
        }
        freq[prefix_sum]++;
    }

    free(freq);
    return count;
}

int main() {
    int nums[] = {1, 0, 1, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int goal = 2;
    printf("Number of subarrays = %d\n", numSubarraysWithSum(nums, n, goal));
    return 0;
}

