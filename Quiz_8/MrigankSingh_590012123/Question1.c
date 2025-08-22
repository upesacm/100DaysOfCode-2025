#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;
    int windowSum = 0;
    // Bug 1: Loop condition should be i < k, not i <= k
    // Because array indices are 0-based, we want to sum first k elements (0 to k-1)
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = k; i < n; i++) 
    {
        // Explanation 2: We subtract arr[i - k] to maintain window size
        // As we add the new element (arr[i]), we remove the oldest element (arr[i-k])
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
