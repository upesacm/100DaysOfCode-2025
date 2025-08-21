#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    return minHeap;
}

void insertMinHeap(MinHeap* minHeap, int key) {
    int i = minHeap->size++;
    while (i && key < minHeap->array[(i - 1) / 2]) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = key;
}

int extractMin(MinHeap* minHeap) {
    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    int i = 0, left, right, smallest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;
        if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest]) {
            smallest = left;
        }
        if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest]) {
            smallest = right;
        }
        if (smallest == i) break;
        int temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[smallest];
        minHeap->array[smallest] = temp;
        i = smallest;
    }
    return root;
}

int minCost(int* ropes, int n) {
    MinHeap* minHeap = createMinHeap(n);
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
    printf("%d\n", minCost(ropes1, n1));

    int ropes2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(ropes2) / sizeof(ropes2[0]);
    printf("%d\n", minCost(ropes2, n2));

    return 0;
}
