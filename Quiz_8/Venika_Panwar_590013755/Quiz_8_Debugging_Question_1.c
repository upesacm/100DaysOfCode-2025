// Solution 1: Maximum Sum Subarray (Sliding Window)

#include <stdio.h>

// Function to find the maximum sum of any subarray of size k
int maxSumSubarray(int arr[], int n, int k)
{
    // Edge case: if k is larger than array size, return -1
    if (n < k) return -1;

    int windowSum = 0;

    // BUG FIX: original code used <= k, which goes out of bounds
    // We only sum the first k elements to form the initial window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    // Initial maximum is the sum of the first window
    int maxSum = windowSum;

    // Slide the window from index k to n-1
    for (int i = k; i < n; i++) 
    {
        // We subtract the element that is leaving the window (arr[i - k])
        // and add the new element entering the window (arr[i])
        windowSum += arr[i] - arr[i - k];

        // Update maxSum if we found a bigger sum
        if (windowSum > maxSum) 
        {
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
    printf("Max sum of subarray of size %d: %d\n", k, result);
    return 0;
}
/*
Explanation of fixes & answers to tasks:
Task 1:
1. Bug in loop condition: `for (int i = 0; i <= k; i++)` → changed to `< k` to avoid out-of-bounds.
Task 2:
2. Why subtract arr[i - k]? → This removes the element that's sliding out of the window so we can add the next one without recalculating the whole sum.
Task 3:
3. Code now runs correctly and preserves O(n) efficiency.
*/
