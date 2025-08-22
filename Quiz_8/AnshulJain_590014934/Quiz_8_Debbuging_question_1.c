#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;
    int windowSum = 0;
    for (int i = 0; i < k; i++) // fixed: changed <= k to < k
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

/* Task Question Answer:
1. Bug in first for loop condition: used <= k instead of < k, causing an out-of-bounds access.
2. We subtract arr[i - k] to remove the element that is sliding out of the current window.
3. Code debugged to correctly output: Max sum of subarray of size 3: 9
*/
