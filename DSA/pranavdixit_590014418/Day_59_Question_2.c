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

void insertMaxHeapPQ(int value) {
    heap[heapSize] = -value; // Negate for max behavior
    bubbleUp(heapSize);
    heapSize++;
}

int extractMaxPQ() {
    if (heapSize == 0) return -1;
    int maxVal = -heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    bubbleDown(0);
    return maxVal;
}

int main() {
    insertMaxHeapPQ(5);
    insertMaxHeapPQ(1);
    insertMaxHeapPQ(10);
    printf("%d\n", extractMaxPQ()); // Output: 10

    heapSize = 0;
    insertMaxHeapPQ(3);
    insertMaxHeapPQ(7);
    insertMaxHeapPQ(2);
    insertMaxHeapPQ(9);
    printf("%d, %d\n", extractMaxPQ(), extractMaxPQ()); // Output: 9, 7
    return 0;
}
