
//1. Bug -  for (int i = 0; i <= k; i++)
//2. Why do we update windowSum by subtracting arr[i - k]? 
// the idea is that instead of recalculating the sum of the next subarray from scratch, we update the sum by removing the element
// that slid out of the window and adding the element that came into the window.
//3. Corrected code
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
