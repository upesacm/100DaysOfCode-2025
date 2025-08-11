#include <stdio.h>

// Finds the maximum sum of any subarray of size k using the sliding window technique
int maxSumSubarray(int arr[], int n, int k)
{
    // If not enough elements for one window, return error
    if (n < k) return -1;

    int windowSum = 0;

    // Bug fix: only sum the first k elements (0 to k-1)
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;  // Start with the sum of the first window

    // Slide the window from index k to n-1
    for (int i = k; i < n; i++) {
        /*
         * Slide window by 1:
         * - Add arr[i]: the new element entering the window
         * - Subtract arr[i - k]: the element leaving from the left
         */
        windowSum += arr[i] - arr[i - k];

        // If this window's sum is greater, update maxSum
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return maxSum;  // Return the highest sum found
}

int main()
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = maxSumSubarray(arr, n, k);
    printf("Max sum of subarray of size %d: %d\n", k, result);

    return 0;
}
