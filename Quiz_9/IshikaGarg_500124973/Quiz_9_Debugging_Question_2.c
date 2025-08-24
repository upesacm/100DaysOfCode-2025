1. Bug in array indexing when calling deleteMax

In main, the heap is defined as:

int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
int size = 6;

Here heap[1]..heap[6] are valid elements. 

That’s consistent with a 1-indexed heap (index 0 unused).

The function deleteMax correctly assumes heap[1] is the root.

So the bug is not in deleteMax, but in potential confusion about indexing. 
  If we ever initialized this heap as 0-indexed, deletion would be wrong. 
  In this case, it’s safe but must be documented clearly: the heap is 1-indexed.

2. Why must we swap before moving index to parent?

In a Max Heap, the root (heap[1]) is always the maximum.
After deleting it, the heap temporarily has a “hole” at the root.
To maintain a complete binary tree, we move the last element to the root.
Then we heapify down to restore the max-heap order.
This ensures both shape property (complete tree) and heap property (parent ≥ children) are preserved.

3. Debugged & Correct Code

#include <stdio.h>

void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(heap, size, largest);
    }
}

void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return; 
    heap[1] = heap[*size];
    (*size)--; 

    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 6;

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    
    return 0;
}

