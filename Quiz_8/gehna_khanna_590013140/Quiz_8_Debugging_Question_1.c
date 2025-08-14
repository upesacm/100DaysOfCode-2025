//1. Bug in the first for loop
//The loop uses for (int i = 0; i <= k; i++). That iterates k+1 elements (indices 0..k) and will access arr[k] which is out of bounds for the first k elements. 
//It should be:for (int i = 0; i < k; i++)  so it sums indices 0 through k-1.
//2.When you slide the window one position right, the new window adds arr[i] (the entering element) and removes the leftmost element of the previous window. 
//The leftmost element of the previous window is at index i - k. So:new_window_sum = old_window_sum + arr[i] - arr[i - k]
//This updates the sum in O(1) time per step.
//3.#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (k <= 0 || n < k) return -1;
    int windowSum = 0;
    for (int i = 0; i < k; i++) {         // <-- fixed condition
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
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
        printf("Invalid input (k > n or k <= 0)\n");
    else
        printf("Max sum of subarray of size %d: %d\n", k, result);
    return 0;
}
