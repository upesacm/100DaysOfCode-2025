// 1. Bug in heapifyUp loop condition:

// Bug: while (index > 1) → Wrong for 1-indexed heaps, should stop when index > 0.

// Fix: while (index > 0 && index > 1) or simply while (index > 1) but ensure parent calculation is correct.

// 2. Why must we swap before moving index to parent?

// Because the heap property may be violated at the current index. Swapping ensures the new value bubbles up correctly before continuing to check higher levels.

// 3. Debugged Code:
#include <stdio.h>

void heapifyUp(int heap[], int index) {
    while (index > 1) { 
        int parent = index / 2;
        if (heap[parent] < heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
        } else {
            break; 
        }
        index = parent;
    }
}

void insert(int heap[], int *size, int value) {
    (*size)++;
    heap[*size] = value;
    heapifyUp(heap, *size);
}

int main() {
    int heap[100] = {0, 50, 30, 40, 10, 20}; 
    int size = 5;

    insert(heap, &size, 60);

    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}
