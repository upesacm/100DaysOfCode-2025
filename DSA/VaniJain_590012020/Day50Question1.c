#include <stdio.h>
#define MAX 1000
int maxSubarraySum(int arr[], int n, int k) 
{
    if (k > n) 
    {
        printf("Subarray size k cannot be greater than array size.\n");
        return -1;
    }
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
    int arr[MAX];
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n > MAX) 
    {
        printf("Array size exceeds maximum allowed.\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of subarray (k): ");
    scanf("%d", &k);
    int result = maxSubarraySum(arr, n, k);
    if (result != -1) 
    {
        printf("Maximum sum of a subarray of size %d is: %d\n", k, result);
    }
    return 0;
}
