#include <stdio.h>

int maxSubArray(int* nums, int n) {
    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < n; i++) {
        if (current_sum < 0) 
            current_sum = nums[i];  // start fresh
        else 
            current_sum += nums[i]; // extend subarray

        if (current_sum > max_sum)
            max_sum = current_sum;
    }

    return max_sum;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Maximum subarray sum = %d\n", maxSubArray(arr, n));
    return 0;
}

