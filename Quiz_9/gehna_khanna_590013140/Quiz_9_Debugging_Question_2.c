//int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
//int size = 6;
//In a heap, the root (index 1) always stores the maximum.After deleting it, we need a new root.If we simply remove it, we’d “break” the complete binary tree property (hole at the top).
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
        // swap
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        // recurse
        heapifyDown(heap, size, largest);
    }
}

void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return;

    // replace root with last element
    heap[1] = heap[*size];
    (*size)--;

    // restore heap property
    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 7; // ✅ fixed bug: should be 7, not 6

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
