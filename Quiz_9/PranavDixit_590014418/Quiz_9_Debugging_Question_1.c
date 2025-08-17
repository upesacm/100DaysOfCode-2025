#include <stdio.h>

// Function to move the inserted node up and restore Max Heap property
void heapifyUp(int heap[], int index)
{
    // BUG FIX 1: condition should be "index > 1", but we also must stop moving
    // once parent is larger. Otherwise unnecessary swaps keep happening.
    while (index > 1)
    {
        int parent = index / 2;

        // BUG FIX 2: swap must happen before moving index upwards,
        // because otherwise the smaller element stays in wrong place.
        if (heap[parent] < heap[index])
        {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;  // move index upward after swapping
        }
        else
        {
            break; // if parent already bigger, no need to continue
        }
    }
}

// Insert a new value into the heap
void insert(int heap[], int *size, int value)
{
    (*size)++;
    heap[*size] = value;
    heapifyUp(heap, *size);
}

int main()
{
    // Initial heap (1-indexed: heap[0] unused)
    int heap[100] = {0, 50, 30, 40, 10, 20};
    int size = 5;

    // Insert new element into Max Heap
    insert(heap, &size, 60);

    // Print heap after insertion
    printf("Heap after inserting 60:\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    // -------------------
    // ANSWERS TO TASKS:
    // 1. Bug in heapifyUp loop: If we don't check properly, the loop may do
    //    unnecessary swaps even when parent is already greater.
    //    We must stop when parent >= child.
    //
    // 2. Swap must be done BEFORE moving index to parent,
    //    otherwise the wrong element stays below and heap property breaks.
    //
    // 3. Code is now debugged: insertion works correctly for Max Heap.
    // -------------------

    return 0;
}
