#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
void findTriplets(int arr[], int n, int target) 
{
    int i, left, right;
    qsort(arr, n, sizeof(int), compare);
    printf("Triplets with sum %d are:\n", target);
    int found = 0;
    for (i = 0; i < n - 2; i++) 
    {
        if (i > 0 && arr[i] == arr[i - 1]) 
        {
            continue;
        }
        left = i + 1;
        right = n - 1;
        while (left < right) 
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target) 
            {
                printf("(%d, %d, %d)\n", arr[i], arr[left], arr[right]);
                found = 1;
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++;
                right--;
            }
            else if (sum < target) 
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
    }
    if (!found) 
    {
        printf("No triplets found.\n");
    }
}
int main() 
{
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    findTriplets(arr, n, target);
    return 0;
}
