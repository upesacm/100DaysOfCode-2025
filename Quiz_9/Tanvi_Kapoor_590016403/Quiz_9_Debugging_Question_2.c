#include <stdio.h>

/*
===================================================================================
Combined Tasks (Insert + Delete in Max Heap)
-----------------------------------------------------------------------------------
Task 1 (Insert Q1):
- Bug in heapifyUp: Typos like heapIl, heap|index), missing braces.
- Corrected: Use heap[], proper syntax, and added braces.

Task 2 (Insert Q1):
- Why swap before moving index to parent?
  Because if we move index before swapping, we lose track of the inserted value.
  Swapping first maintains heap property correctly.

Task 3 (Insert Q1):
- Fixed and working insert() and heapifyUp() functions.

Task 1 (Delete Q2):
- Bug in array indexing: Typo in `heapl`, `heap|1]`, `heap(right]`.
- Fixed by using correct syntax: `heap[]`, `heap[1]`, etc.

Task 2 (Delete Q2):
- Why replace root with last element before heapifyDown?
  Because we remove the root (max value), and to maintain the complete binary tree,
  we replace it with the last node and fix the heap using heapifyDown.

Task 3 (Delete Q2):
- Fixed and working deleteMax() and heapifyDown() functions.
===================================================================================
*/

// Function to restore Max Heap property from a given index upward (for insert)
void heapifyUp(int heap[], int index) {
    while (index > 1) {
        int parent = index / 2;
        if (heap[parent] < heap[index]) {
            // Swap parent and current
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else {
            break; // Heap property satisfied
        }
    }
}

// Insert a new value into the Max Heap
void insert(int heap[], int *size, int value) {
    (*size)++;
    heap[*size] = value;
    heapifyUp(heap, *size);
}

// Function to restore Max Heap property from a given index downward (for delete)
void heapifyDown(int heap[], int size, int index) {
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right <= size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        // Swap current and largest child
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        // Recursively heapify down
        heapifyDown(heap, size, largest);
    }
}

// Delete the maximum element (root) from the Max Heap
void deleteMax(int heap[], int *size) {
    if (*size == 0) {
        return; // Heap is empty
    }

    // Replace root with last element
    heap[1] = heap[*size];
    (*size)--;

    // Restore heap property
    heapifyDown(heap, *size, 1);
}

// Utility function to print the heap
void printHeap(int heap[], int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main driver code
int main() {
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 6;

    printf("Original Heap: ");
    printHeap(heap, size);

    // Insert a new element
    insert(heap, &size, 60);
    printf("After Inserting 60: ");
    printHeap(heap, size);

    // Delete the max (root)
    deleteMax(heap, &size);
    printf("After Deleting Max: ");
    printHeap(heap, size);

    return 0;
}
