#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    int parent = (i - 1) / 2;
    if (i && heap[i] < heap[parent]) {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

int extractMin(int heap[], int *size) {
    int minVal = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return minVal;
}

void insertHeap(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    heapifyUp(heap, *size - 1);
}

void sortKSortedArray(int arr[], int n, int k) {
    int heap[k + 1], size = 0, index = 0;

    for (int i = 0; i <= k && i < n; i++)
        insertHeap(heap, &size, arr[i]);

    for (int i = k + 1; i < n; i++) {
        arr[index++] = extractMin(heap, &size);
        insertHeap(heap, &size, arr[i]);
    }

    while (size > 0)
        arr[index++] = extractMin(heap, &size);
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    sortKSortedArray(arr, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

