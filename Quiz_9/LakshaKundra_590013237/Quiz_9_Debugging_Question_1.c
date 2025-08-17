//The bug is we are updating index = parent even when no swap happens.
// line is- while (index > 1)

//answer 2
//If we move the index before swapping, we lose track of the child that needed to be swapped, breaking the heap property.

//correct code 
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
            index = parent;
        }
        else
        {
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
    int heap[100] = {0, 50, 30, 40, 10, 20};
    int size = 5;
    insert(heap, &size, 60);
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
