#include <stdio.h>
#define MAX 1000
void findSubarrayWithSum(int arr[], int n, int target) 
{
    int start = 0, end = 0;
    int currentSum = 0;
    while (end < n) 
    {
        currentSum += arr[end];
        while (currentSum > target && start <= end) 
        {
            currentSum -= arr[start];
            start++;
        }
        if (currentSum == target) 
        {
            printf("Subarray with sum %d found from index %d to %d (1-based)\n", target, start + 1, end + 1);
            return;
        }
        end++;
    }
    printf("No subarray with the given sum %d was found.\n", target);
}
int main() 
{
    int arr[MAX];
    int n, target;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    findSubarrayWithSum(arr, n, target);
    return 0;
}
