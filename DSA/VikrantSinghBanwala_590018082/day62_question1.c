#include <stdio.h>
#include <stdlib.h>

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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;
    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap *minHeap, int key) {
    if (minHeap->size == minHeap->capacity) return;
    minHeap->array[minHeap->size] = key;
    int i = minHeap->size;
    minHeap->size++;

    while (i != 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i]) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap *minHeap) {
    if (minHeap->size <= 0) return -1;
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0];
    }

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

int connectRopes(int *ropes, int n) {
    MinHeap *minHeap = createMinHeap(n);
    for (int i = 0; i < n; i++) {
        insertMinHeap(minHeap, ropes[i]);
    }

    int totalCost = 0;
    while (minHeap->size > 1) {
        int first = extractMin(minHeap);
        int second = extractMin(minHeap);
        int cost = first + second;
        totalCost += cost;
        insertMinHeap(minHeap, cost);
    }

    free(minHeap->array);
    free(minHeap);
    return totalCost;
}

int main() {
    int ropes1[] = {4, 3, 2, 6};
    int n1 = sizeof(ropes1) / sizeof(ropes1[0]);
    printf("%d\n", connectRopes(ropes1, n1));

    int ropes2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(ropes2) / sizeof(ropes2[0]);
    printf("%d\n", connectRopes(ropes2, n2));

    return 0;
}
