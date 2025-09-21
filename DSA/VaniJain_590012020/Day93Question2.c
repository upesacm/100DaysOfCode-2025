#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int main() 
{
    int N;
    printf("Enter size of the array: ");
    scanf("%d", &N);
    if (N <= 0) 
    {
        printf("Array size must be positive.\n");
        return 0;
    }
    int arr[N];
    printf("Enter array elements:\n");
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int currentSum = arr[0];
    int maxSum = arr[0];
    for (int i = 1; i < N; i++) 
    {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    printf("Maximum contiguous subarray sum = %d\n", maxSum);
    return 0;
}
