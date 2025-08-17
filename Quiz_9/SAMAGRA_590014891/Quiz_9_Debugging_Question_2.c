#include <stdio.h>

// Function to restore Max Heap property after deletion
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

        // Continue heapifying down until the property is restored
        heapifyDown(heap, size, largest);
    }
}

// Function to delete the maximum element (root) from a Max Heap
void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return;

    /*
       Task 1: The bug was in array indexing.
       In main(), size was initialized as 6 even though there were 7 elements.
       Corrected by setting size = 7.
    */

    /*
       Task 2: We replace the root with the last element because a heap
       must always remain a complete binary tree. Only the last element
       can move to the root without breaking completeness. After that,
       heapifyDown is applied to restore the Max Heap property.
    */

    heap[1] = heap[*size];  
    (*size)--;  
    heapifyDown(heap, *size, 1); 
}

int main()
{
    // Initial heap (1-indexed). Total 7 elements.
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 7;  // Corrected size

    deleteMax(heap, &size);

    /*
       Task 3: Debugged code now deletes the maximum element correctly
       and maintains the Max Heap property.
    */
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}


