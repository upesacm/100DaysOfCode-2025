#include <stdio.h>

#define MAX 100
int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void bubbleUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void bubbleDown(int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        bubbleDown(largest);
    }
}

void insertHeap(int val) {
    if (size >= MAX) return;
    heap[size] = val;
    bubbleUp(size);
    size++;
}

int deleteRoot() {
    if (size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[--size];
    bubbleDown(0);
    return root;
}

void printHeap() {
    for (int i = 0; i < size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertHeap(20);
    insertHeap(15);
    insertHeap(8);
    deleteRoot();
    printHeap(); // Example: Heap after operations

    size = 0;
    insertHeap(30);
    insertHeap(25);
    insertHeap(10);
    insertHeap(35);
    deleteRoot();
    insertHeap(40);
    printHeap(); // Example: Heap after operations
    return 0;
}
