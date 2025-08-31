#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
int maximizeSum(int arr[], int n, int k) 
{
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n && k > 0; i++) 
    {
        if (arr[i] < 0) 
        {
            arr[i] = -arr[i];
            k--;
        }
    }
    if (k % 2 == 1) 
    {
        int minIndex = 0;
        for (int i = 1; i < n; i++) 
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }
        arr[minIndex] = -arr[minIndex];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int main() 
{
    int arr[] = {-2, 0, 5, -1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int result = maximizeSum(arr, n, k);
    printf("Maximum sum after %d operations: %d\n", k, result);
    return 0;
}
