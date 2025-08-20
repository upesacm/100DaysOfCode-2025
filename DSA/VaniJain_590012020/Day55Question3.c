#include <stdio.h>
#include <stdlib.h>
int countSubarraysWithSum(int arr[], int n, int goal) 
{
    int prefixSum = 0;
    int count = 0;
    int *freq = (int *)calloc(n + 1, sizeof(int));
    freq[0] = 1;  
    for (int i = 0; i < n; i++) 
    {
        prefixSum += arr[i];
        if (prefixSum - goal >= 0) 
        {
            count += freq[prefixSum - goal];
        }
        freq[prefixSum]++;
    }
    free(freq);
    return count;
}
int main() 
{
    int n, goal;
    printf("Enter size of binary array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements (0 or 1): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter goal sum: ");
    scanf("%d", &goal);
    int result = countSubarraysWithSum(arr, n, goal);
    printf("Number of subarrays with sum = %d is %d\n", goal, result);
    return 0;
}
