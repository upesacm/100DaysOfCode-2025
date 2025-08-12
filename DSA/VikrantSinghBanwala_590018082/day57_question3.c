#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

typedef struct {
    HeapNode *data;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->data = (HeapNode *)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    return heap;
}

void insertMinHeap(MinHeap *heap, HeapNode node) {
    heap->data[heap->size++] = node;
    int i = heap->size - 1;
    while (i != 0 && heap->data[(i - 1) / 2].value > heap->data[i].value) {
        HeapNode temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

HeapNode extractMin(MinHeap *heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap->size && heap->data[left].value < heap->data[smallest].value) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right].value < heap->data[smallest].value) {
            smallest = right;
        }
        if (smallest == i) break;
        HeapNode temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        i = smallest;
    }
    return root;
}

void mergeKSortedArrays(int **arrays, int k, int *sizes, int *result, int *resultSize) {
    MinHeap *heap = createMinHeap(k);
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            HeapNode node = {arrays[i][0], i, 0};
            insertMinHeap(heap, node);
        }
    }
    
    *resultSize = 0;
    while (heap->size > 0) {
        HeapNode minNode = extractMin(heap);
        result[(*resultSize)++] = minNode.value;
        if (minNode.elementIndex + 1 < sizes[minNode.arrayIndex]) {
            HeapNode nextNode = {arrays[minNode.arrayIndex][minNode.elementIndex + 1], minNode.arrayIndex, minNode.elementIndex + 1};
            insertMinHeap(heap, nextNode);
        }
    }
    
    free(heap->data);
    free(heap);
}

int main() {
    int *arrays[3];
    int sizes[3] = {2, 2, 2};
    int result[100];
    int resultSize;

    arrays[0] = (int[]){1, 3};
    arrays[1] = (int[]){2, 4};
    arrays[2] = (int[]){5, 6};
    mergeKSortedArrays(arrays, 3, sizes, result, &resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    int *arrays2[3];
    int sizes2[3] = {3, 3, 2};
    int result2[100];
    int resultSize2;

    arrays2[0] = (int[]){1, 4, 5};
    arrays2[1] = (int[]){1, 3, 4};
    arrays2[2] = (int[]){2, 6};
    mergeKSortedArrays(arrays2, 3, sizes2, result2, &resultSize2);
    for (int i = 0; i < resultSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    return 0;
}
