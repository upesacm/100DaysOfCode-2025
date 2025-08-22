//The in the first for loop condition
//The loop is written as:
//for (int i = 0; i <= k; i++)

//After computing the sum of the first window (arr[0]..arr[k-1]), each slide moves the window one position right. At step i (where i starts at k) we add the new element arr[i] (entering the window) and must remove the element that left the window — that element is arr[i - k]. So the update
//windowSum += arr[i] - arr[i - k];
//efficiently computes the sum of the next window in O(1) time per move.

//correct code
#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k || k <= 0) return -1;
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
