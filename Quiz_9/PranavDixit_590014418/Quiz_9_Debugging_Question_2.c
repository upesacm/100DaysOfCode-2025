#include <stdio.h>

// Function to restore Max Heap property by moving element down
void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    // check left child
    if (left <= size && heap[left] > heap[largest])
        largest = left;

    // check right child
    if (right <= size && heap[right] > heap[largest])
        largest = right;

    // if root is not the largest, swap and continue heapifying down
    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(heap, size, largest);
    }
}

// Function to delete maximum element (root) from Max Heap
void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return;

    // BUG FIX 1: we must replace the root with the last element,
    // not just delete it, otherwise the heap becomes incomplete.
    heap[1] = heap[*size];

    // reduce heap size
    (*size)--;

    // restore heap property
    heapifyDown(heap, *size, 1);
}

int main()
{
    // Initial heap (1-indexed)
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 6;

    // Delete max (root element)
    deleteMax(heap, &size);

    // Print heap after deletion
    printf("Heap after deleting max:\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    // -------------------
    // ANSWERS TO TASKS:
    //
    // 1. Bug in array indexing:
    //    In main, heap is given as {0, 50, 30, 40, 10, 20, 35}, so it's 1-indexed.
    //    We must always treat heap[1] as root. If someone uses 0-indexing here,
    //    deleteMax will break. So the fix is: stick to 1-indexing everywhere.
    //
    // 2. Why replace root with last element?
    //    Because when we remove the root, the tree would have a "hole".
    //    To maintain completeness of the binary tree, we bring the last node
    //    up to the root, then push it down to restore heap order.
    //
    // 3. Debugged code:
    //    Now deleteMax works correctly for all cases.
    // -------------------

    return 0;
}
