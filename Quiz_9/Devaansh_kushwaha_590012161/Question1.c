#include <stdio.h>

void heapifyUp(int heap[], int index)
{
    while (index > 1)
    {
        int parent = index / 2;
        if (heap[parent] < heap[index])
        {
            // Swap parent and child
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            
            // Move up to continue heapifying
            index = parent;
        }
        else
        {
            // Heap property satisfied, no more swaps needed
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
    
    printf("Original heap: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    
    insert(heap, &size, 60);
    
    printf("After inserting 60: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    
    return 0;
}
