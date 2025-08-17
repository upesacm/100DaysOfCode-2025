// 1. Bug in array indexing when calling deleteMax:
// There is no explicit bug in the indexing when calling deleteMax as long as the heap is 1-indexed and size is correct.
// Just ensure the heap size correctly reflects the number of elements and heap array is 1-indexed throughout.
// If size or indexing mismatches happen elsewhere, that would cause issues.

// 2. Why do we replace the root with the last element before heapifying down?
// We replace the root with the last element because we are effectively removing the root (max element).
// Using the last element in the root position allows us to maintain the complete binary tree shape,
// and then we restore the heap property by heapifying down from the root.

// 3. Debugged code for correct deletion:

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

    heap[1] = heap[*size];  // Replace root with last element
    (*size)--;              // Decrease heap size
    heapifyDown(heap, *size, 1);  // Restore max-heap property
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed heap initialization
    int size = 6;
    deleteMax(heap, &size);  // Delete max element (root)
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}