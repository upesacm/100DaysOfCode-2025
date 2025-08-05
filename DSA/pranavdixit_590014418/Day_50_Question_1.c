#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k) {
    int maxSum = 0, windowSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += arr[i];
    maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    return maxSum;
}

int main() {
    int arr[] = {1, 4, 2, 10};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Max sum of subarray of size %d: %d\n", k, maxSumSubarray(arr, n, k));
    return 0;
}
