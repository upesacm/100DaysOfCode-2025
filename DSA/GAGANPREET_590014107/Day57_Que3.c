#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 1000

typedef struct {
    int value;     
    int arrIndex;  
    int elemIndex; 
} HeapNode;

typedef struct {
    HeapNode heap[MAX_HEAP_SIZE];
    int size;
} MinHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].value < h->heap[smallest].value)
        smallest = left;
    if (right < h->size && h->heap[right].value < h->heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void heapifyUp(MinHeap* h, int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && h->heap[i].value < h->heap[parent].value) {
        swap(&h->heap[i], &h->heap[parent]);
        heapifyUp(h, parent);
    }
}

void insert(MinHeap* h, HeapNode node) {
    h->heap[h->size] = node;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode extractMin(MinHeap* h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}


int* mergeKSortedArrays(int** arrays, int* sizes, int k, int* mergedSize) {
    MinHeap heap = {.size = 0};
    int totalSize = 0;

    
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            HeapNode node = {arrays[i][0], i, 0};
            insert(&heap, node);
            totalSize += sizes[i];
        }
    }

    int* result = (int*)malloc(sizeof(int) * totalSize);
    int index = 0;

    while (heap.size > 0) {
        HeapNode minNode = extractMin(&heap);
        result[index++] = minNode.value;

        int nextIndex = minNode.elemIndex + 1;
        if (nextIndex < sizes[minNode.arrIndex]) {
            HeapNode nextNode = {
                arrays[minNode.arrIndex][nextIndex],
                minNode.arrIndex,
                nextIndex
            };
            insert(&heap, nextNode);
        }
    }

    *mergedSize = totalSize;
    return result;
}

int main() {
    
    int a1[] = {1, 3}, a2[] = {2, 4}, a3[] = {5, 6};
    int* arrays1[] = {a1, a2, a3};
    int sizes1[] = {2, 2, 2};
    int k1 = 3, mergedSize1;
    int* result1 = mergeKSortedArrays(arrays1, sizes1, k1, &mergedSize1);

    printf("Merged array: ");
    for (int i = 0; i < mergedSize1; i++)
        printf("%d ", result1[i]);
    printf("\n");
    free(result1);

    
    int b1[] = {1, 4, 5}, b2[] = {1, 3, 4}, b3[] = {2, 6};
    int* arrays2[] = {b1, b2, b3};
    int sizes2[] = {3, 3, 2};
    int k2 = 3, mergedSize2;
    int* result2 = mergeKSortedArrays(arrays2, sizes2, k2, &mergedSize2);

    printf("Merged array: ");
    for (int i = 0; i < mergedSize2; i++)
        printf("%d ", result2[i]);
    printf("\n");
    free(result2);

    return 0;
}
