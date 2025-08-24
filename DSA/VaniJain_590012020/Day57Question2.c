#include <stdio.h>
int isMaxHeap(int arr[], int n) 
{
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;  
        int right = 2 * i + 2;  
        if (left < n && arr[i] < arr[left])
            return 0;
        if (right < n && arr[i] < arr[right])
            return 0;
    }
    return 1; 
}
int main() 
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    if (isMaxHeap(arr, n))
        printf("The array satisfies the Max-Heap property.\n");
    else
        printf("The array does NOT satisfy the Max-Heap property.\n");
    return 0;
}
