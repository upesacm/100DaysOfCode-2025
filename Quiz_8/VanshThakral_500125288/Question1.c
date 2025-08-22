 // BUG
 // for (int i = 0; i <= k; i++)
 // The bug is in <= k — this runs k+1 times instead of k times.

// This will cause out-of-bounds access when i = k (because we only want the first k elements to initialize windowSum).

// Correct condition:
// for (int i = 0; i < k; i++) 

//WHY?
// This is the essence of the sliding window technique.

// At each step, we:

// Add the new element entering the window (arr[i]).

// Remove the oldest element leaving the window (arr[i - k]).

// This way, we reuse the sum from the previous step instead of recalculating from scratch — making it O(n) instead of O(n × k).

#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;

    int windowSum = 0;
    for (int i = 0; i < k; i++) 
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < n; i++) 
    {
        windowSum += arr[i] - arr[i - k];
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
