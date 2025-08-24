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
    
    printf("The heap after insertion is: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return 0;
}

//The bug in the heapifyUp function's while loop condition is that it continues to run even if the parent is already larger than the current node. This results in unnecessary iterations.
//The swap must occur before updating the index to its parent to ensure we're comparing the correct element in the next iteration.