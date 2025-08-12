#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;

    int windowSum = 0;

    // Task 1: Okay, so here was the first bug.
    // Originally this loop ran with `i <= k`, which actually grabs k+1 elements.
    // We only want the first k elements for our initial window sum.
    for (int i = 0; i < k; i++) 
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    for (int i = k; i < n; i++) 
    {
        // Task 2: Why are we subtracting arr[i - k] here?
        // Imagine our sliding window moving forward by one element.
        // We "kick out" the element that's no longer in the window (arr[i - k])
        // and "invite in" the new element (arr[i]).
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

    // Task 3: The bug’s fixed now, so this should cleanly print 9 for our test case.
    printf("Max sum of subarray of size %d: %d\n", k, result);

    return 0;
}
