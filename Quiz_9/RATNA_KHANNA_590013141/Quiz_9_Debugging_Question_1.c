//1.while (index > 1)
//2.Because the purpose of heapifyUp is to move the newly inserted element upwards until the heap property holds.
//If the new element is larger than its parent, swap them so it climbs higher.After swapping, we set index = parent and continue checking higher levels.
//Without swapping first, the element would never reach the correct position.
//3.#include <stdio.h>

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

            // move index up
            index = parent;
        }
        else
        {
            // already in correct place
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
    int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed max heap
    int size = 5;

    insert(heap, &size, 60);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
