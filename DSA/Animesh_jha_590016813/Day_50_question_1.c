#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) {
        printf("Invalid: k is larger than array size\n");
        return -1;
    }

    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

    int window_sum = max_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    return max_sum;
}

int main() {
    int arr[] = {100,200,300,400};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxSumSubarray(arr, n, k);
    printf("Maximum sum of subarray of size %d is: %d\n", k, result);

    return 0;
}
