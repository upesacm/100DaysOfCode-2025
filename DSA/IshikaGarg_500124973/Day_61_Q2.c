#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void insert(int heap[], int *n, int value) {
    heap[*n] = value;
    (*n)++;
    heapifyUp(heap, *n - 1);
}

void deleteRoot(int heap[], int *n) {
    if (*n <= 0) return;
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
}

void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[MAX];
    int n = 0;

    insert(heap, &n, 20);
    insert(heap, &n, 15);
    insert(heap, &n, 8);
    deleteRoot(heap, &n);

    printf("Heap after operations: ");
    printHeap(heap, n);

    insert(heap, &n, 30);
    insert(heap, &n, 25);
    insert(heap, &n, 10);
    insert(heap, &n, 35);
    deleteRoot(heap, &n);
    insert(heap, &n, 40);

    printf("Final Heap: ");
    printHeap(heap, n);
    return 0;
}

