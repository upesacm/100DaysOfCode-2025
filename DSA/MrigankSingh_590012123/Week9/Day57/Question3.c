#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    int arrayIdx;
    int elementIdx;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heap implementation
typedef struct {
    HeapNode *heapArray;
    int capacity;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->heapArray = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    return minHeap;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heapArray[left].value < minHeap->heapArray[smallest].value) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->heapArray[right].value < minHeap->heapArray[smallest].value) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&minHeap->heapArray[idx], &minHeap->heapArray[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertHeap(MinHeap* minHeap, HeapNode node) {
    if (minHeap->size == minHeap->capacity) {
        return;
    }
    minHeap->heapArray[minHeap->size] = node;
    int i = minHeap->size;
    minHeap->size++;

    while (i != 0 && minHeap->heapArray[(i - 1) / 2].value > minHeap->heapArray[i].value) {
        swap(&minHeap->heapArray[(i - 1) / 2], &minHeap->heapArray[i]);
        i = (i - 1) / 2;
    }
}

HeapNode extractMin(MinHeap* minHeap) {
    if (minHeap->size <= 0) {
        HeapNode emptyNode = {0, 0, 0};
        return emptyNode;
    }
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->heapArray[0];
    }
    HeapNode root = minHeap->heapArray[0];
    minHeap->heapArray[0] = minHeap->heapArray[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

int* mergeKSortedArrays(int** arrays, int k, int* sizes, int* resultSize) {

    int totalElements = 0;
    for (int i = 0; i < k; i++) {
        totalElements += sizes[i];
    }
    *resultSize = totalElements;
    int* result = (int*)malloc(totalElements * sizeof(int));

    MinHeap* minHeap = createMinHeap(k);

    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            HeapNode node = {arrays[i][0], i, 1};
            insertHeap(minHeap, node);
        }
    }

    int index = 0;
    while (minHeap->size > 0) {
        HeapNode node = extractMin(minHeap);
        result[index++] = node.value;
        if (node.elementIdx < sizes[node.arrayIdx]) {
            HeapNode nextNode = {arrays[node.arrayIdx][node.elementIdx], node.arrayIdx, node.elementIdx + 1};
            insertHeap(minHeap, nextNode);
        }
    }

    free(minHeap->heapArray);
    free(minHeap);
    return result;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int k;
    printf("Enter the number of sorted arrays (K): ");
    scanf("%d", &k);

    int** arrays = (int**)malloc(k * sizeof(int*));
    int* sizes = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        printf("Enter the size of array %d: ", i + 1);
        scanf("%d", &sizes[i]);
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));
        printf("Enter the elements of array %d (sorted): ", i + 1);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    int resultSize;
    int* result = mergeKSortedArrays(arrays, k, sizes, &resultSize);

    printf("Merged sorted array: ");
    printArray(result, resultSize);

    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);
    free(result);

    return 0;
}
