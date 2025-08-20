#include <stdio.h>
#include <stdlib.h>
int isMaxHeap(int arr[], int n) 
{
    for (int i = 0; i <= (n - 2) / 2; i++) 
    { 
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left])
            return 0; 
        if (right < n && arr[i] < arr[right])
            return 0; 
    }
    return 1;
}
int areSameHeap(int arr1[], int n1, int arr2[], int n2) 
{
    if (n1 != n2) return 0;
    if (!isMaxHeap(arr1, n1) || !isMaxHeap(arr2, n2))
        return 0;
    for (int i = 0; i < n1; i++) 
    {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}
int main() 
{
    int n1, n2;
    printf("Enter size of first heap array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of first heap array: ");
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);
    printf("Enter size of second heap array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of second heap array: ");
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);
    if (areSameHeap(arr1, n1, arr2, n2))
        printf("Both arrays represent the SAME heap structure.\n");
    else
        printf("Arrays do NOT represent the same heap structure.\n");
    return 0;
}
