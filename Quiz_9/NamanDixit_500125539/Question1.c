//1. while (index > 1)
//This condition is not the bug itself, but the placement of index = parent; is wrong.
//Currently, even if no swap happens, index is still moved up. That breaks the heapify process.

//2. Swapping restores the Max Heap property. Without it, a smaller parent could stay below a larger child. 
// After each swap, the element may still be bigger than its new parent, so bubbling up continues until correct.

//3. corrected code
#include <stdio.h>

void heapifyUp(int heap[], int index)
{
    while (index > 1)
    {
        int parent = index / 2;
        if (heap[parent] < heap[index])
        {
            // swap
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            // move up
            index = parent;
        }
        else
        {
            break; // stop if heap property satisfied
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
    int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed heap
    int size = 5;

    insert(heap, &size, 60);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
