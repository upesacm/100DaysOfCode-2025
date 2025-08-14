#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->array = (int *)malloc(capacity * sizeof(int));
    return maxHeap;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleUp(MaxHeap *maxHeap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (maxHeap->array[parent] >= maxHeap->array[index]) {
            break;
        }
        swap(&maxHeap->array[parent], &maxHeap->array[index]);
        index = parent;
    }
}

void insert(MaxHeap *maxHeap, int key) {
    if (maxHeap->size == maxHeap->capacity) {
        return;
    }
    maxHeap->array[maxHeap->size] = key;
    maxHeap->size++;
    bubbleUp(maxHeap, maxHeap->size - 1);
}

void bubbleDown(MaxHeap *maxHeap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest]) {
        largest = left;
    }
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&maxHeap->array[index], &maxHeap->array[largest]);
        bubbleDown(maxHeap, largest);
    }
}

int extractMax(MaxHeap *maxHeap) {
    if (maxHeap->size == 0) {
        return INT_MIN;
    }
    int root = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size--;
    bubbleDown(maxHeap, 0);
    return root;
}

void freeMaxHeap(MaxHeap *maxHeap) {
    free(maxHeap->array);
    free(maxHeap);
}

int main() {
    MaxHeap *maxHeap = createMaxHeap(10);
    insert(maxHeap, 5);
    insert(maxHeap, 1);
    insert(maxHeap, 10);
    printf("%d\n", extractMax(maxHeap));
    
    insert(maxHeap, 3);
    insert(maxHeap, 7);
    insert(maxHeap, 2);
    insert(maxHeap, 9);
    printf("%d\n", extractMax(maxHeap));
    printf("%d\n", extractMax(maxHeap));
    
    freeMaxHeap(maxHeap);
    return 0;
}
