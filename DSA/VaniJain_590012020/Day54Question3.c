#include <stdio.h>
int numSubarrayProductLessThanK(int arr[], int n, int k)
{
    if (k <= 1) return 0; 
    int left = 0;
    long long product = 1;
    int count = 0;
    for (int right = 0; right < n; right++) 
    {
        product *= arr[right];
        while (product >= k && left <= right) 
        {
            product /= arr[left];
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}
int main() 
{
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = numSubarrayProductLessThanK(arr, n, k);
    printf("Number of contiguous subarrays with product less than %d: %d\n", k, result);
    return 0;
}
