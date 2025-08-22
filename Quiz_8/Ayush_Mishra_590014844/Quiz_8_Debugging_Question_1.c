#include<stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (k <= 0 || n < k) return -1;  // invalid case

    int windowSum = 0;
    // Sum of first k elements
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int result = maxSumSubarray(arr, n, k);

    if (result == -1) {
        printf("Invalid input (k=%d, n=%d)\n", k, n);
    } else {
        printf("Max sum of subarray of size %d: %d\n", k, result);
    }
    return 0;
}
