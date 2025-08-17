/*1. Identify the bug in array indexing when calling deleteMax.
-- The array has 7 elements, but size is incorrectly set to 6.
2. Why do we replace the root with the last element before heapify
-- The root (index 1) holds the maximum value in a Max Heap.
    To delete it, we:
     i)Remove the root.
     ii)Replace it with the last element to maintain the complete binary tree structure.
    iii)Then heapify down to restore the Max Heap property.
   This avoids gaps and keeps the tree balanced.
3. Debug the code for correct deletion in all cases.*/\
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
    int size = 7; 

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
