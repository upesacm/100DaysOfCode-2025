// 1. The loop condition is 'i <= k' but it should be 'i < k'. If we use '<=', we include one extra element, which goes out of bounds for
//    subarray initialization.

// 2. In the sliding window technique, when we move the window forward by one position, we remove the element that goes out of the window
//    (arr[i - k]) and add the new element (arr[i]). This ensures O(1) time complexity for updating the sum instead of recalculating from
//    scratch.

// 3. Debugged code : 

/*
#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k) return -1;
    int windowSum = 0;

    for (int i = 0; i < k; i++)  // Fix : change '<=' to '<'
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for(int i = k; i < n; i++)
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
*/
