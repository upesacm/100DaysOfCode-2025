/*
1. Bug in the loop condition: The loop condition in heapifyUp should be index > 1 because the heap is 1-indexed. 
This means that the root node is at index 1, and we should stop when we reach the root.

2. Why swap before moving index to parent: We must swap before moving the index to the parent
 because we need to ensure that the parent node is larger than the current node. If we move the index to the parent
  first and then check, we might miss the opportunity to swap if the current node is larger than the parent.
  
3. correct code:*/
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
