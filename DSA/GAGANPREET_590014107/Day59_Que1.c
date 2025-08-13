
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int *)malloc(capacity * sizeof(int));
    return minHeap;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleUp(MinHeap *minHeap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (minHeap->array[parent] <= minHeap->array[index]) {
            break;
        }
        swap(&minHeap->array[parent], &minHeap->array[index]);
        index = parent;
    }
}

void insert(MinHeap *minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        return;
    }
    minHeap->array[minHeap->size] = key;
    minHeap->size++;
    bubbleUp(minHeap, minHeap->size - 1);
}

void bubbleDown(MinHeap *minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest]) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&minHeap->array[index], &minHeap->array[smallest]);
        bubbleDown(minHeap, smallest);
    }
}

int extractMin(MinHeap *minHeap) {
    if (minHeap->size == 0) {
        return INT_MAX;
    }
    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    bubbleDown(minHeap, 0);
    return root;
}

void freeMinHeap(MinHeap *minHeap) {
    free(minHeap->array);
    free(minHeap);
}

int main() {
    MinHeap *minHeap = createMinHeap(10);
    insert(minHeap, 3);
    insert(minHeap, 2);
    insert(minHeap, 15);
    printf("%d\n", extractMin(minHeap));
    
    insert(minHeap, 10);
    insert(minHeap, 5);
    insert(minHeap, 20);
    insert(minHeap, 8);
    printf("%d\n", extractMin(minHeap));
    printf("%d\n", extractMin(minHeap));
    
    freeMinHeap(minHeap);
    return 0;
}
