// 1. Issue with the heapifyUp loop:
// The condition ‘while (index > 1)’ is correct and needs no change since the heap is 1-indexed.
// The real problem is that the index is always moved to the parent after checking, even if no swap occurs.
// If no swap happens, the index should stay to avoid unnecessary iterations and preserve heap order.

// 2. Why do we swap before moving index to parent?
// Swapping must happen first to ensure the max-heap property at the current level is restored.
// Moving the index before swapping would lose track of the node violating the heap property, breaking heap integrity.

// 3. Refined code with fixes and clear logic:
#include <stdio.h>

void heapifyUp(int heap[], int index)
{
    while (index > 1)
    {
        int parent = index / 2;
        if (heap[parent] < heap[index])
        {
            // Swap the current node with its parent to maintain max-heap property
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            // Move up to the parent node after swap
            index = parent;
        }
        else
        {
            // Heap property satisfied, stop moving up
            break;
        }
    }
}

void insert(int heap[], int *size, int value)
{
    (*size)++;              // Increase size to accommodate new element
    heap[*size] = value;    // Insert new value at end
    heapifyUp(heap, *size); // Restore heap property upwards
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20};  // 1-based indexing; 0th unused
    int size = 5;

    insert(heap, &size, 60);  // Insert 60 into the max heap

    // Print the heap array after insertion
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return 0;
}
