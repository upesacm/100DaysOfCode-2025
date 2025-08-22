#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void insertMinHeap(MinHeap *heap, int value) {
    if (heap->size < heap->capacity) {
        heap->data[heap->size++] = value;
        int i = heap->size - 1;
        while (i != 0 && heap->data[(i - 1) / 2] > heap->data[i]) {
            int temp = heap->data[i];
            heap->data[i] = heap->data[(i - 1) / 2];
            heap->data[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    } else if (value > heap->data[0]) {
        heap->data[0] = value;
        int i = 0;
        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < heap->size && heap->data[left] < heap->data[smallest]) {
                smallest = left;
            }
            if (right < heap->size && heap->data[right] < heap->data[smallest]) {
                smallest = right;
            }
            if (smallest == i) break;
            int temp = heap->data[i];
            heap->data[i] = heap->data[smallest];
            heap->data[smallest] = temp;
            i = smallest;
        }
    }
}

void kLargestElements(int *arr, int n, int k) {
    MinHeap *heap = createMinHeap(k);
    for (int i = 0; i < n; i++) {
        insertMinHeap(heap, arr[i]);
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", heap->data[i]);
    }
    free(heap->data);
    free(heap);
}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    kLargestElements(arr, n, k);
    return 0;
}
