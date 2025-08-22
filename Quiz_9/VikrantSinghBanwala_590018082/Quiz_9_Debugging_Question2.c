/*
1. Bug in array indexing: The bug is in the deleteMax function where the last element is assigned to the root. 
The correct element to replace the root should be heap[*size], but after decrementing the size, 
it should be heap[*size + 1] since the size is decremented before the heapify operation.

2. Why replace the root with the last element: We replace the root with the last element to maintain the complete
 binary tree property of the heap. After removing the maximum element (the root), we need to fill that position
  with the last element to keep the structure intact, and then we "heapify down" to restore the heap property.
  
3. correct code:*/
#include <stdio.h>

void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    if (left <= size && heap[left] > heap[largest])
        largest = left;
    if (right <= size && heap[right] > heap[largest])
        largest = right;
    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(heap, size, largest);
    }
}

void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return;
    heap[1] = heap[*size];
    (*size)--;
    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 6;
    deleteMax(heap, &size);
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
