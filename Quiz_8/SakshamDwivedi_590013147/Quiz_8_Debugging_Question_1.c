#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (k <= 0 || n < k) return -1; //added k<=0 check as well to avoid conflict of k being lesser than 0
    int windowSum = 0;
    for (int i = 0; i < k; i++)        //Fixed i <= k, as i <= k would have iterated it k+1 times
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k];  // We subtract arr[i-k] because that's the element sliding out of the window moving forward.
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
