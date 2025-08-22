#include <stdio.h>

// Task 1: Fix the bug in the loop condition
// Task 2: Understand why we subtract arr[i - k] when sliding the window
// Task 3: Debug the entire code to get the correct output

// Function to find the maximum sum of any subarray of size k
int maxSumSubarray(int arr[], int n, int k) {
    // Edge case: if the array has fewer than k elements
    if (n < k) return -1;

    int windowSum = 0;

    // ✅ Task 1 fix: Correct loop condition should be i < k (not i <= k)
    // This initializes the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // ✅ Task 2: Slide the window from index k to n - 1
    // At each step, subtract the element leaving the window (arr[i - k])
    // and add the new element entering the window (arr[i])
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];

        // Update maxSum if current window sum is greater
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return maxSum;
}

int main() {
    // ✅ Task 3: Debug main function and fix declaration syntax
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = maxSumSubarray(arr, n, k);
    printf("Max sum of subarray of size %d: %d\n", k, result);

    return 0;
}
