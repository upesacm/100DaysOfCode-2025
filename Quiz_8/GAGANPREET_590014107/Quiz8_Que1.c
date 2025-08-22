/*
1.Bug is in condition i < k it should be i <= k. 
This is because we want to sum first k elements, and using <= will cause an out-of-bounds access.

2.Why we update windowSum by subtracting arr[i - k]?
This is done to maintain sum of current window of size k.
When we move window to right, we add new element arr[i] and remove element that is no longer 
in window, which is arr[i - k].

Debugged code:*/
#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;
    int windowSum = 0;
    
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;
    for (int i = k; i < n; i++) 
    {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) 
            maxSum = windowSum;
    }
    return maxSum;
}

int main() 
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Max sum of subarray of size %d: %d\n", k, maxSumSubarray(arr, n, k));
    return 0;
}
