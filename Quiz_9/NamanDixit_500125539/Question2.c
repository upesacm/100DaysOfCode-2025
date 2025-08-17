//1. heap[1] = heap[*size];
//(*size)--;
//heapifyDown(heap, *size, 1);
//you overwrite the root with heap[*size] before decrementing. This causes an off-by-one bug in indexing.
// Correct order: decrement size first, then use the last element.

//2. The root (max) must be deleted.
//To keep the heap as a complete binary tree, we fill the gap at root with the last element (rightmost leaf).
//Then we heapify down to restore the max-heap property.


//3. Corrected code
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

    // Move last element to root
    heap[1] = heap[*size];
    (*size)--; // reduce heap size

    // Restore max heap property
    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 6; // number of elements

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
