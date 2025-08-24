#include <stdio.h>

/*
---------------------------------------------------------------
Task 1: Bug in heapifyUp loop condition
- The loop condition `while (index > 1)` is logically correct.
- The real bugs were:
  1. Syntax errors (missing braces `{}`, semicolons).
  2. Typo: `heapIl` should be `heap[]`.
  3. Typo: `heap[parent] = heap|index);` should be `heap[parent] = heap[index];`
---------------------------------------------------------------
Task 2: Why we must swap before moving index to parent
- Swapping ensures the larger element moves up.
- If you move `index = parent` before swapping, you lose the position of the inserted element.
---------------------------------------------------------------
*/

void heapifyUp(int heap[], int index) {
    while (index > 1) {
        int parent = index / 2;
        if (heap[parent] < heap[index]) {
            // Swap parent and current node to maintain Max Heap property
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            // Move index to parent to continue heapifying up
            index = parent;
        } else {
            // If heap property is satisfied, stop
            break;
        }
    }
}

// Task 3: Debugged and correct insert function
void insert(int heap[], int *size, int value) {
    (*size)++;              // Increase heap size
    heap[*size] = value;    // Add new element at the end
    heapifyUp(heap, *size); // Restore heap property
}

int main() {
    // Initial Max Heap (1-indexed): [0, 50, 30, 40, 10, 20]
    // Index 0 is unused for easier parent/child calculations
    int heap[100] = {0, 50, 30, 40, 10, 20}; 
    int size = 5;

    // Insert a new element into the heap
    insert(heap, &size, 60); // Inserting value 60

    // Print the heap after insertion
    printf("Heap after insertion: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}
