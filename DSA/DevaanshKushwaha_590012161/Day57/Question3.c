#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;
    
    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;
    
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(HeapNode* heap, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

int* mergeKSortedArrays(int** arrays, int* sizes, int k, int* totalSize) {
    int total = 0;
    for (int i = 0; i < k; i++) {
        total += sizes[i];
    }
    *totalSize = total;
    
    int* result = (int*)malloc(total * sizeof(int));
    HeapNode* heap = (HeapNode*)malloc(k * sizeof(HeapNode));
    int heapSize = 0;
    
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            heap[heapSize].value = arrays[i][0];
            heap[heapSize].arrayIndex = i;
            heap[heapSize].elementIndex = 0;
            heapSize++;
        }
    }
    
    buildMinHeap(heap, heapSize);
    
    int resultIndex = 0;
    
    while (heapSize > 0) {
        HeapNode root = heap[0];
        result[resultIndex++] = root.value;
        
        if (root.elementIndex + 1 < sizes[root.arrayIndex]) {
            heap[0].value = arrays[root.arrayIndex][root.elementIndex + 1];
            heap[0].elementIndex = root.elementIndex + 1;
            minHeapify(heap, heapSize, 0);
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
            if (heapSize > 0) {
                minHeapify(heap, heapSize, 0);
            }
        }
    }
    
    free(heap);
    return result;
}

int main() {
    int k;
    scanf("%d", &k);
    
    int** arrays = (int**)malloc(k * sizeof(int*));
    int* sizes = (int*)malloc(k * sizeof(int));
    
    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }
    
    int totalSize;
    int* result = mergeKSortedArrays(arrays, sizes, k, &totalSize);
    
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);
    free(result);
    
    return 0;
}
