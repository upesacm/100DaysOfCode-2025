// Bug in the heapifyUp loop condition
// while (index > 1)
//This by itself isn’t wrong, but the index must only move up if a swap happens.
//In your code, even if no swap is done, you still update index = parent;.
//This makes elements stop bubbling up correctly.
//Fix: Move index = parent; inside the swap condition.


//Why must we swap before moving index to parent?
//	•	In a Max Heap, the new element must “bubble up” until the parent is larger.
//	•	If we move index first without swapping, the child remains larger than the parent → heap property breaks.
//	•	Swapping first ensures the child goes up correctly, then we continue checking higher parents.

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
            heap[index] = 
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

    insert(heap, &size, 60);  // insert 60 into Max Hea

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
