#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HeapNode heap[], int i, int size) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;
    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, smallest, size);
    }
}

void buildMinHeap(HeapNode heap[], int size) {
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(heap, i, size);
}

int main() {
    int k;
    printf("Enter number of arrays: ");
    scanf("%d", &k);
    int sizes[k];
    int *arrays[k];

    for (int i = 0; i < k; i++) {
        printf("Enter size of array %d: ", i + 1);
        scanf("%d", &sizes[i]);
        arrays[i] = (int *)malloc(sizes[i] * sizeof(int));
        printf("Enter elements of array %d: ", i + 1);
        for (int j = 0; j < sizes[i]; j++)
            scanf("%d", &arrays[i][j]);
    }

    HeapNode heap[k];
    int totalSize = 0;
    for (int i = 0; i < k; i++) {
        heap[i].value = arrays[i][0];
        heap[i].arrayIndex = i;
        heap[i].elementIndex = 0;
        totalSize += sizes[i];
    }

    buildMinHeap(heap, k);
    int result[totalSize], idx = 0;

    while (idx < totalSize) {
        result[idx++] = heap[0].value;
        int ai = heap[0].arrayIndex;
        int ei = ++heap[0].elementIndex;

        if (ei < sizes[ai])
            heap[0].value = arrays[ai][ei];
        else
            heap[0].value = __INT_MAX__;

        heapify(heap, 0, k);
    }

    printf("Merged array: ");
    for (int i = 0; i < totalSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    for (int i = 0; i < k; i++)
        free(arrays[i]);

    return 0;
}
