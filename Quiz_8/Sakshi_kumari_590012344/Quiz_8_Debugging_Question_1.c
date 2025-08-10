1. Identify the bug in the first for loop condition.
  
  The loop:
for (int i = 0; i <= k; i++)
    windowSum += arr[i];

The problem is <= k.
This goes one step too far, because array indexes start from 0.
If k = 3, valid indexes are 0, 1, 2 → total 3 elements.
But <= k tries to go till 3, which means we access arr[3] by mistake when calculating the first sum.
To fix it we need to chnage it to:
for (int i = 0; i < k; i++)
This will sum exactly the first k elements without going out of bounds.

2. Why do we update windowSum by subtracting arr[i - k]?
  
Sliding window means we move the group of k elements one step at a time.
When we move right:
We add the new number coming into the window (arr[i])
We remove the number that is going out from the left (arr[i - k])
Example:
If the window was [2, 1, 5] and the next number is 1,
we drop 2 and add 1.
That’s why we do:
windowSum += arr[i] - arr[i - k];

3. Debug the code for the correct output.
  
  #include <stdio.h>
int maxSumSubarray(int arr[], int n, int k)
{
    if (n < k || k <= 0) return -1; 

    int windowSum = 0;

    
    for (int i = 0; i < k; i++) {
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

    if (result != -1)
        printf("Max sum of subarray of size %d: %d\n", k, result);
    else
        printf("Invalid input.\n");

    return 0;
}

Max sum of subarray of size 3: 9





