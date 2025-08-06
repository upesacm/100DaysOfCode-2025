#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
bool hasPairWithSum(int arr[], int n, int x)
{
    qsort(arr, n, sizeof(int), compare);
    int left = 0;
    int right = n - 1;
    while (left < right) 
    {
        int sum = arr[left] + arr[right];
        if (sum == x) 
        {
            return true;
        } 
        else if (sum < x)
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return false;
}
int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 8};
    int x1 = 16;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    if (hasPairWithSum(arr1, n1, x1)) 
    {
        printf("true\n");
    } 
    else
    {
        printf("false\n");
    }

    int arr2[] = {1, 2, 4, 3, 6};
    int x2 = 10;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    if (hasPairWithSum(arr2, n2, x2))
    {
        printf("true\n");
    } 
    else 
    {
        printf("false\n");
    }
    return 0;
}
