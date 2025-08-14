#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int arrIndex;
    int elemIndex;
} HeapNode;

void swapNode(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].value < heap[smallest].value)
        smallest = left;
    if (right < n && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swapNode(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void mergeKSortedArrays(int **arrays, int *sizes, int k) {
    HeapNode heap[k];
    int totalSize = 0;

    for (int i = 0; i < k; i++) {
        heap[i].value = arrays[i][0];
        heap[i].arrIndex = i;
        heap[i].elemIndex = 0;
        totalSize += sizes[i];
    }

    for (int i = k / 2 - 1; i >= 0; i--)
        heapify(heap, k, i);

    printf("Merged array: ");
    for (int count = 0; count < totalSize; count++) {
        HeapNode root = heap[0];
        printf("%d ", root.value);

        if (root.elemIndex + 1 < sizes[root.arrIndex]) {
            heap[0].value = arrays[root.arrIndex][root.elemIndex + 1];
            heap[0].elemIndex++;
        } else {
            heap[0].value = 1e9; 
        }
        heapify(heap, k, 0);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    int *arrays[] = {arr1, arr2, arr3};
    int sizes[] = {3, 3, 2};
    int k = 3;

    mergeKSortedArrays(arrays, sizes, k);
    return 0;
}

