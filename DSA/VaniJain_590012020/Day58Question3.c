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
void replaceRoot(int arr[], int n, int newValue) 
{
    if (n <= 0) 
    {
        printf("Heap is empty, cannot replace root.\n");
        return;
    }
    arr[0] = newValue;      
    maxHeapify(arr, n, 0);  
}
int main() 
{
    int n, newValue;
    printf("Enter size of heap: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter heap elements (Max-Heap): ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter new value for root: ");
    scanf("%d", &newValue);
    replaceRoot(arr, n, newValue);
    printf("Heap after root replacement: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
