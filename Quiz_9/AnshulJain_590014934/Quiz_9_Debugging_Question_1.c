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
            index = parent;  // move index only after swap
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
    int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed
    int size = 5;
    insert(heap, &size, 60);
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

/*
Task Question Answer:
1. Bug: index was updated to parent even when no swap was made, breaking heapify condition.
2. Swap must be done first to maintain Max Heap property before moving index upward.
3. Fixed by moving 'index = parent' inside swap block and adding break if no swap needed.
*/
