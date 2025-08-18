//while (index > 1)
//Heap property says: every parent ≥ children.If child > parent, we swap them to restore heap property.Only after swapping does it make sense to move index up to parent (since the inserted value has moved there).If we move without swapping, we might skip necessary fixes and break the heap structure.
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

            // now move up
            index = parent;
        }
        else
        {
            // already in correct position
            break;
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
