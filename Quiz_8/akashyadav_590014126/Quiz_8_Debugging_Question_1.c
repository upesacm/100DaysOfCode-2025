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

//The bug is in the condition i <= k it causes the loop to iterate k+1 times, attempting to access arr[k], which is out of bounds for the first window.
//Instead of summing all k elements for each window, we simply add the new element and subtract the one that has moved out. This makes the operation an efficient O(1) instead of O(k) for each window, leading to an overall time complexity of O(n) for the algorithm.
//