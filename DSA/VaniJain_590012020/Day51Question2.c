#include <stdio.h>
#include <limits.h>
#define MAX 1000
int smallestSubarrayWithSumGreaterThanX(int arr[], int n, int x) 
{
    int minLen = INT_MAX;
    int start = 0, end = 0, currentSum = 0;
    while (end < n) 
    {
        while (currentSum <= x && end < n) 
        {
            currentSum += arr[end];
            end++;
        }
        while (currentSum > x && start < n) 
        {
            if (end - start < minLen) 
            {
                minLen = end - start;
            }
            currentSum -= arr[start];
            start++;
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}
int main() 
{
    int arr[MAX], n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d positive integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of x: ");
    scanf("%d", &x);
    int result = smallestSubarrayWithSumGreaterThanX(arr, n, x);
    if (result > 0) 
    {
        printf("Smallest subarray length with sum greater than %d is: %d\n", x, result);
    } 
    else 
    {
        printf("No subarray with sum greater than %d was found.\n", x);
    }
    return 0;
}
