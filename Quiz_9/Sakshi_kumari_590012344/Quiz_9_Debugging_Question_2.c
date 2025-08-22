Q1. Identify the bug in array indexing when calling deleteMax
In main, the heap array is written as:
int heap[100] = {0, 50, 30, 40, 10, 20, 35}; 
int size = 6;
This array is 1-indexed, meaning the heap starts at index 1 (not 0).

But here size = 6 (which is correct since there are 6 elements).
The bug is not in the function, but in understanding: if we mistakenly treat the heap as 0-indexed, the code breaks.
  So the important point: the program must always treat the heap as 1-indexed when calling deleteMax.

  Q2. Why do we replace the root with the last element before heapifying down?
In a Max Heap, the root (index 1) always has the largest element.

When we delete the maximum, we must remove the root.

To avoid breaking the tree structure, we put the last element at the root temporarily.

Then we call heapifyDown to push it down into the correct position.
This ensures both the complete tree property and the heap order property are preserved.

Q3. Debugged Code

Here’s the corrected version of the code with fixes and comments:
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
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 6;

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

