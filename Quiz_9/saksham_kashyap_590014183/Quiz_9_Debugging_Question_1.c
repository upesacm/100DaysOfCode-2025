// 1. Bug in the heapifyUp loop condition:
// The loop condition should be 'index > 1', which is correct in the original code. No change needed here.
// However, the bug is that after swapping the parent and current node, 'index = parent;' happens regardless, even if no swap occurs.
// If no swap is done, 'index' should not move up, otherwise the loop unnecessarily continues.

// 2. Why must we swap before moving index to parent?
// Swapping needs to be done before updating the index to parent so that the heap property is maintained correctly.
// If we move the index before swapping, we lose track of the current node that violates the heap property and do not fix it.

// 3. Corrected code:
#include <stdio.h>

void heapifyUp(int heap[], int index)
{
    while (index > 1)
    {
        int parent = index / 2;
        if (heap[parent] < heap[index])
        {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent; // Move up only when a swap happens
        }
        else
        {
            break; // Stop if no swap needed (heap property is satisfied)
        }
    }
}

void insert(int heap[], int *size, int value)
{
    (*size)++;
    heap[*size] = value;
    heapifyUp(heap, *size);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed
    int size = 5;
    insert(heap, &size, 60);
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}