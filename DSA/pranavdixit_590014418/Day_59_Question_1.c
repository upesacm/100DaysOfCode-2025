#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void bubbleDown(int index) {
    while (index * 2 + 1 < heapSize) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = left;

        if (right < heapSize && heap[right] < heap[left])
            smallest = right;

        if (heap[index] > heap[smallest]) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

void insertMinHeap(int value) {
    if (heapSize >= MAX_SIZE) return;
    heap[heapSize] = value;
    bubbleUp(heapSize);
    heapSize++;
}

int extractMin() {
    if (heapSize == 0) return -1;
    int minVal = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    bubbleDown(0);
    return minVal;
}

int main() {
    insertMinHeap(3);
    insertMinHeap(2);
    insertMinHeap(15);
    printf("%d\n", extractMin()); // Output: 2

    heapSize = 0;
    insertMinHeap(10);
    insertMinHeap(5);
    insertMinHeap(20);
    insertMinHeap(8);
    printf("%d, %d\n", extractMin(), extractMin()); // Output: 5, 8
    return 0;
}
