// 1. The Bug in the First Loop Condition
// The first loop, for (int i = 0; i <= k; i++), is intended to calculate the sum of the initial window of size k. However, the condition i <= k causes the loop to run k+1 times (for indices 0 through k), summing one element too many.
//Solution - The loop condition should be i < k to correctly sum the first k elements of the array (at indices 0, 1, ..., k-1).

// 2.  Why do we update windowSum by subtracting arr[i - k]?
// solution  The expression windowSum += arr[i] - arr[i - k] is the core of the sliding window's efficiency.
    //  arr[i] is the *new element* entering the window from the right as we slide.
    //  arr[i - k] is the *old element* that is leaving the window from the left.
    //  By adding the new element and subtracting the old one, we update the sum for the new window in a single, constant-time operation, instead of re-calculating the sum of all k elements.

// Correct Code 
#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) {
        printf("Invalid input: array size is smaller than window size.\n");
        return -1; 
    }

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    int maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }
    return maxSum;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = maxSumSubarray(arr, n, k);

    if (result != -1) {
        printf("Max sum of subarray of size %d: %d\n", k, result);
    }
    return 0;
}
