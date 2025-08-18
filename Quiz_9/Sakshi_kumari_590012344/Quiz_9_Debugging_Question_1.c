Q1. Identify the bug in the heapifyUp loop condition.
  In the original code, the loop was written as: while (index > 1)
This means the loop keeps moving up the tree even if the parent is already greater than the child.
That’s a bug because the heap property is already satisfied, so no more work is needed.
  Fix:- while (index > 1 && heap[index / 2] < heap[index])
  Now the loop only runs when the parent is smaller than the child.

Q2. Why must we swap before moving index to parent?
  We need to swap first because:
If the child is bigger than the parent, the heap property is violated.
Swapping fixes this immediately.
Then we move index up to check the next level.
If we moved the index first without swapping, the bigger element would stay stuck below and never reach its correct position.

Q3. Debugged Code:-
  
#include <stdio.h>
  
void heapifyUp(int heap[], int index)
{
    while (index > 1 && heap[index / 2] < heap[index])
    {
        int parent = index / 2;

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
      
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
    int heap[100] = {0, 50, 30, 40, 10, 20}; 
    int size = 5;

    insert(heap, &size, 60);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

