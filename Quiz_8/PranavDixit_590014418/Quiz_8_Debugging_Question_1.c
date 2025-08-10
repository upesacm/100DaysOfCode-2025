/*
    Debugging Question: Maximum sum of subarray of size k (sliding window)

    Task 1: Identify the bug in the first for loop condition.
    - Bug: the loop used `i <= k`, which sums k+1 elements and reads out of bounds when k == n-1.
    - Fix: use `i < k` to sum exactly the first k elements.

    Task 2: Why do we update windowSum by subtracting arr[i - k]?
    - Because when we slide the window one step to the right we must remove the element
      that falls out of the window (the one k positions behind the current index).
      So we add the new entering element arr[i] and subtract the leaving element arr[i-k].
*/

#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;

    int windowSum = 0;
    /* sum the first k elements (fixed: i < k) */
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    /* slide the window: add arr[i] (new) and subtract arr[i-k] (leaving) */
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
    if (result == -1)
        printf("k is larger than array size\n");
    else
        printf("Max sum of subarray of size %d: %d\n", k, result);
    return 0;
}
