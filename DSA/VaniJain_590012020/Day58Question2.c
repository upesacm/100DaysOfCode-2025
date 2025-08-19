#include <stdio.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(int arr[], int n, int i) 
{
    int largest = i;      
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n) 
{
    for (int i = (n / 2) - 1; i >= 0; i--) 
    {
        maxHeapify(arr, n, i);
    }
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
    buildMaxHeap(arr, n);
    printf("Array converted to Max-Heap: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
