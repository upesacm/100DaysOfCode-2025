// he following C code is supposed to find the maximum sum of any subarray of size k using the sliding window technique, but it has bugs. Find and fix them.  

// #include <stdio.h>

// int maxSumSubarray(int arr[], int n, int k)
// {
//     if (n < k) return -1;
//     int windowSum = 0;
//     for (int i = 0; i <= k; i++)
//     {
//         windowSum += arr[i];
//     }
//     int maxSum = windowSum;
//     for (int i = k; i < n; i++) 
//       {
//         windowSum += arr[i] - arr[i - k];
//         if (windowSum > maxSum) 
//         {
//             maxSum = windowSum;
//         }
//     }
//     return maxSum;
// }

// int main() 
// {
//     int arr[] = {2, 1, 5, 1, 3, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 3;
//     int result = maxSumSubarray(arr, n, k);
//     printf("Max sum of subarray of size %d: %d\n", k,           result);
//     return 0;
// }

// Tasks:
// 1. Identify the bug in the first for loop condition.
// 2. Why do we update windowSum by subtracting arr[i - k]?
// 3. Debug the code for the correct output.

#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k)
    {
        printf("Invalid input: array size is less than subarray size.\n");
        return -1; // Indicates an error
    }

    int windowSum = 0;
    // Calculate sum of the first window of size k
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window from the beginning to the end of the array
    for (int i = k; i < n; i++) 
    {
        // Update window sum in O(1) time
        windowSum += arr[i] - arr[i - k];
        
        // Update the maximum sum if needed
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

    if (result != -1)
    {
        printf("Max sum of subarray of size %d: %d\n", k, result);
    }
    
    return 0;
}