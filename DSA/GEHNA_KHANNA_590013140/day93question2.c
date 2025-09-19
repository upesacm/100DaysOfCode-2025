#include <stdio.h>

int maxSubArray(int* nums, int n) {
    int max_sum = nums[0], current = nums[0];
    for (int i = 1; i < n; i++) {
        if (current + nums[i] > nums[i]) current += nums[i];
        else current = nums[i];
        if (current > max_sum) max_sum = current;
    }
    return max_sum;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("%d\n", maxSubArray(nums, n));
    return 0;
}
