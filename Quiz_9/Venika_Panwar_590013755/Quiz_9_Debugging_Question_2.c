// 1. Issue related to array indexing in deleteMax:
// The indexing approach works fine when the heap uses 1-based indexing and the size variable is accurate.
// The key is to keep the heap size and indexing consistent throughout to avoid errors when accessing elements.
// Problems only arise if there’s a mismatch in how the heap is represented or how size is maintained.

// 2. Why do we put the last element at the root before heapifying down?
// Removing the root means the max element is taken out, but to keep the complete binary tree structure intact,
// we move the last element to the root position temporarily, then push it down correctly to restore heap order.

// 3. Updated and clean code with explanations:

#include <stdio.h>

void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    // Check if left child exists and is greater than current largest
    if (leftChild <= size && heap[leftChild] > heap[largest])
        largest = leftChild;

    // Check if right child exists and is greater than current largest
    if (rightChild <= size && heap[rightChild] > heap[largest])
        largest = rightChild;

    // If largest changed, swap and continue heapifying down
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
        return;  // Heap is empty, nothing to delete

    // Move last element to root to maintain tree shape
    heap[1] = heap[*size];
    (*size)--;  // Reduce heap size as max element is removed

    // Restore max-heap order from root downwards
    heapifyDown(heap, *size, 1);
}

int main()
{
    // Initial heap with 1-based indexing, 0th index unused
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 6;

    deleteMax(heap, &size);  // Remove max element

    // Print updated heap array after deletion
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}
