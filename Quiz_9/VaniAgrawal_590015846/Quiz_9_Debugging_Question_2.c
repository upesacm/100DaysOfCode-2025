// 1. Bug in array indexing when calling deleteMax:

// Inside heapifyDown, comparisons used <= size incorrectly. Must check <= size carefully for valid children.

// 2. Why replace root with last element before heapifying down?

// Because deleting the max removes the root, and to maintain a complete binary tree, the last element is moved to root, then pushed down to restore heap property.

// 3. Debugged Code:
#include <stdio.h>

void heapifyDown(int heap[], int size, int index) {
    while (index * 2 <= size) {
        int left = 2 * index;
        int right = 2 * index + 1;
        int largest = index;

        if (left <= size && heap[left] > heap[largest])
            largest = left;
        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            index = largest; 
        } else {
            break; 
        }
    }
}

void deleteMax(int heap[], int *size) {
    if (*size == 0) return;

    heap[1] = heap[*size]; 
    (*size)--;
    heapifyDown(heap, *size, 1);
}

int main() {
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; 
    int size = 6;

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}
