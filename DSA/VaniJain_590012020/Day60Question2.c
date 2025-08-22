#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(int heap[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) 
    {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}
void insertMaxHeap(int heap[], int *n, int key) 
{
    int i = (*n)++;
    heap[i] = key;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) 
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int extractMax(int heap[], int *n) 
{
    int root = heap[0];
    heap[0] = heap[--(*n)];
    maxHeapify(heap, *n, 0);
    return root;
}
void minHeapify(int heap[], int n, int i) 
{
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) 
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}
void insertMinHeap(int heap[], int *n, int key) 
{
    int i = (*n)++;
    heap[i] = key;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) 
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int extractMin(int heap[], int *n) 
{
    int root = heap[0];
    heap[0] = heap[--(*n)];
    minHeapify(heap, *n, 0);
    return root;
}
int maxHeap[MAX_SIZE], minHeap[MAX_SIZE];
int maxHeapSize = 0, minHeapSize = 0;
void balanceHeaps() 
{
    if (maxHeapSize > minHeapSize + 1) 
    {
        insertMinHeap(minHeap, &minHeapSize, extractMax(maxHeap, &maxHeapSize));
    } else if (minHeapSize > maxHeapSize) 
    {
        insertMaxHeap(maxHeap, &maxHeapSize, extractMin(minHeap, &minHeapSize));
    }
}
void addNumber(int num) 
{
    if (maxHeapSize == 0 || num <= maxHeap[0]) 
    {
        insertMaxHeap(maxHeap, &maxHeapSize, num);
    } 
    else 
    {
        insertMinHeap(minHeap, &minHeapSize, num);
    }
    balanceHeaps();
}
double getMedian() 
{
    if (maxHeapSize == minHeapSize)
        return (maxHeap[0] + minHeap[0]) / 2.0;
    else
        return maxHeap[0]; 
}
int main() 
{
    int n, num;
    printf("Enter number of elements in stream: ");
    scanf("%d", &n);
    printf("Enter the elements one by one:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        addNumber(num);
        printf("Median after insertion %d: %.2f\n", num, getMedian());
    }
    return 0;
}
