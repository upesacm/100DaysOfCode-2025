/*1. Identify the bug in the heapifyUp loop condition.
-- while (index > 1)
2. Why must we swap before moving index to parent?
-- Swapping ensures that the newly inserted value bubbles up to its correct position. If we move index to parent before swapping, 
   we lose track of the original value that needs to be moved up.
3. Debug the code to correctly insert into the Max Heap.*/
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
