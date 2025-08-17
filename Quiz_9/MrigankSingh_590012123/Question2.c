#include <stdio.h>

void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    // Compare with left child
    if (left <= size && heap[left] > heap[largest])
        largest = left;

    // Compare with right child
    if (right <= size && heap[right] > heap[largest])
        largest = right;

    // If root is not largest, swap with largest child
    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        // Continue heapifying down
        heapifyDown(heap, size, largest);
    }
}

void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return;

    // Replace root with last element
    heap[1] = heap[*size];

    // Reduce heap size
    (*size)--;

    // Restore heap property from root
    heapifyDown(heap, *size, 1);
}

int main()
{
    // 1-indexed heap
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 6; // BUG: Should be 7, since there are 7 valid elements (index 1–7)

    // ✅ FIX: set correct size
    size = 7;

    deleteMax(heap, &size);

    // Expected output after deleting 50: 40 30 35 10 20
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

/*
Tasks Answers:
1. Bug: size initialized as 6 instead of 7 (since array has 7 elements from index 1 to 7).
2. We replace root with last element because removing root leaves a "hole";
   moving last element up keeps array complete while restoring heap property with heapifyDown.
3. Debug: Fixed heap size indexing issue → correct deletion now.
*/
