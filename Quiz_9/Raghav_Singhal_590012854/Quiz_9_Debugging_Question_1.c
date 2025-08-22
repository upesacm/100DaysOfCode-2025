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
        }
        else break;
        index = parent;
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


// Tasks:
// 1. Identify the bug in the heapifyUp loop condition.
// There should be break if parent is largest
// 2. Why must we swap before moving index to parent?
// to make the pareant largest and maintain max heap property
// 3. Debug the code to correctly insert into the Max Heap.
// 60 30 50 10 20 40 