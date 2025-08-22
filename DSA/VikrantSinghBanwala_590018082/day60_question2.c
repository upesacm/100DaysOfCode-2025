#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->data = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(Heap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        maxHeapify(heap, largest);
    }
}

void minHeapify(Heap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMaxHeap(Heap *heap, int value) {
    if (heap->size < heap->capacity) {
        heap->data[heap->size++] = value;
        for (int i = (heap->size / 2) - 1; i >= 0; i--) {
            maxHeapify(heap, i);
        }
    }
}

void insertMinHeap(Heap *heap, int value) {
    if (heap->size < heap->capacity) {
        heap->data[heap->size++] = value;
        for (int i = (heap->size / 2) - 1; i >= 0; i--) {
            minHeapify(heap, i);
        }
    }
}

void balanceHeaps(Heap *maxHeap, Heap *minHeap) {
    if (maxHeap->size > minHeap->size + 1) {
        insertMinHeap(minHeap, maxHeap->data[0]);
        maxHeap->data[0] = maxHeap->data[maxHeap->size - 1];
        maxHeap->size--;
        maxHeapify(maxHeap, 0);
    } else if (minHeap->size > maxHeap->size) {
        insertMaxHeap(maxHeap, minHeap->data[0]);
        minHeap->data[0] = minHeap->data[minHeap->size - 1];
        minHeap->size--;
        minHeapify(minHeap, 0);
    }
}

double getMedian(Heap *maxHeap, Heap *minHeap) {
    if (maxHeap->size > minHeap->size) {
        return maxHeap->data[0];
    } else {
        return (maxHeap->data[0] + minHeap->data[0]) / 2.0;
    }
}

void findMedianInStream(int *stream, int n) {
    Heap *maxHeap = createHeap(n);
    Heap *minHeap = createHeap(n);
    
    for (int i = 0; i < n; i++) {
        if (maxHeap->size == 0 || stream[i] <= maxHeap->data[0]) {
            insertMaxHeap(maxHeap, stream[i]);
        } else {
            insertMinHeap(minHeap, stream[i]);
        }
        balanceHeaps(maxHeap, minHeap);
        printf("%.1f ", getMedian(maxHeap, minHeap));
    }
    printf("\n");

    free(maxHeap->data);
    free(maxHeap);
    free(minHeap->data);
    free(minHeap);
}

int main() {
    int stream1[] = {5, 15, 1, 3};
    int n1 = sizeof(stream1) / sizeof(stream1[0]);
    findMedianInStream(stream1, n1);

    int stream2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(stream2) / sizeof(stream2[0]);
    findMedianInStream(stream2, n2);

    return 0;
}
