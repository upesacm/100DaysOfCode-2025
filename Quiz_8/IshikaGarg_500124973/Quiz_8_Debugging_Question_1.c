1.
Bug in the first for loop
The loop uses i <= k. That iterates k+1 elements (indices 0..k) but you only want the first k elements (indices 0..k-1).
Fix: use for (int i = 0; i < k; i++).

2.
When the window slides one step to the right (we add arr[i] as the new rightmost element), we must remove
the previous leftmost element from the sum. At iteration i (where i is the index of the newly added element), the element that leaves the window is at index i - k. So we update:

windowSum = windowSum + arr[i] - arr[i - k];
This keeps the sum of the current window of size k in O(1) time per step.


3.
#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k)
{
    if (k <= 0 || n < k) return -1; // validate input

    int windowSum = 0;
    // initialize first window (0 .. k-1)
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // slide the window from i = k to n-1
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
        printf("Invalid input: window size k is larger than array or non-positive\n");
    else
        printf("Max sum of subarray of size %d: %d\n", k, result);

    return 0;
}
