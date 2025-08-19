#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int heap[], int n, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) 
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}
void buildMinHeap(int heap[], int n) 
{
    for (int i = (n/2) - 1; i >= 0; i--) 
    {
        heapify(heap, n, i);
    }
}
void printKLargest(int arr[], int n, int k) 
{
    if (k > n) 
    {
        printf("k cannot be greater than array size.\n");
        return;
    }
    int heap[k];
    for (int i = 0; i < k; i++) 
    {
        heap[i] = arr[i];
    }
    buildMinHeap(heap, k);
    for (int i = k; i < n; i++) 
    {
        if (arr[i] > heap[0]) 
        {
            heap[0] = arr[i];
            heapify(heap, k, 0);
        }
    }
    printf("The %d largest elements are: ", k);
    for (int i = 0; i < k; i++) 
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main() 
{
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    printKLargest(arr, n, k);
    return 0;
}
