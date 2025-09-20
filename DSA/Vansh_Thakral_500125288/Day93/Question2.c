#include <stdio.h>

int maxSubArray(int* nums, int n) {
    int max_sum = nums[0];
    int curr_sum = nums[0];

    for (int i = 1; i < n; i++) {
        curr_sum = (nums[i] > curr_sum + nums[i]) ? nums[i] : curr_sum + nums[i];
        if (curr_sum > max_sum) max_sum = curr_sum;
    }
    return max_sum;
}

int main() {
    int arr1[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Maximum Subarray Sum = %d\n", maxSubArray(arr1, n1)); // Output: 6

    int arr2[] = {1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Maximum Subarray Sum = %d\n", maxSubArray(arr2, n2)); // Output: 1
    return 0;
}

