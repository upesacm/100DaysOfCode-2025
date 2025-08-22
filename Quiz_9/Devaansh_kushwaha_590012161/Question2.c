#include <stdio.h>

void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    
    // Find largest among root, left child and right child
    if (left <= size && heap[left] > heap[largest])
        largest = left;
    if (right <= size && heap[right] > heap[largest])
        largest = right;
    
    // If largest is not root, swap and recursively heapify
    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(heap, size, largest);
    }
}

int deleteMax(int heap[], int *size)
{
    // Handle empty heap case
    if (*size == 0) {
        printf("Heap is empty!\n");
        return -1; // Return error code
    }
    
    // Store the maximum value to return
    int maxValue = heap[1];
    
    // Handle single element case
    if (*size == 1) {
        (*size)--;
        return maxValue;
    }
    
    // Replace root with last element
    heap[1] = heap[*size];
    (*size)--;
    
    // Heapify down from root
    heapifyDown(heap, *size, 1);
    
    return maxValue;
}

void printHeap(int heap[], int size) {
    printf("Heap: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 6;
    
    printf("Original ");
    printHeap(heap, size);
    
    int deleted = deleteMax(heap, &size);
    printf("Deleted maximum: %d\n", deleted);
    printf("After deletion ");
    printHeap(heap, size);
    
    // Test multiple deletions
    printf("\nTesting multiple deletions:\n");
    while (size > 0) {
        deleted = deleteMax(heap, &size);
        printf("Deleted: %d, Remaining ", deleted);
        printHeap(heap, size);
    }
    
    // Test deletion from empty heap
    printf("\nTrying to delete from empty heap:\n");
    deleteMax(heap, &size);
    
    return 0;
}
