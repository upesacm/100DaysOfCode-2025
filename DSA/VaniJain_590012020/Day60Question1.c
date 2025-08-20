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
    int left = 2 * i + 1;
    int right = 2 * i + 2;
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
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}
int extractMin(int heap[], int *n) 
{
    if (*n <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return root;
}
void insertHeap(int heap[], int *n, int key) 
{
    int i = (*n)++;
    heap[i] = key;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) 
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void sortKSortedArray(int arr[], int n, int k) 
{
    int heap[k + 1];
    int heapSize = 0;
    for (int i = 0; i < k + 1 && i < n; i++) 
    {
        insertHeap(heap, &heapSize, arr[i]);
    }
    int index = 0;
    for (int i = k + 1; i < n; i++) 
    {
        arr[index++] = extractMin(heap, &heapSize);
        insertHeap(heap, &heapSize, arr[i]);
    }
    while (heapSize > 0) 
    {
        arr[index++] = extractMin(heap, &heapSize);
    }
}

int main() 
{
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter value of k: ");
    scanf("%d", &k);
    sortKSortedArray(arr, n, k);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
