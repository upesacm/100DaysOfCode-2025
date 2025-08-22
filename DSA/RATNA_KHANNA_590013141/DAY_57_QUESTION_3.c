#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int arrIndex;
    int elemIndex;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapify(HeapNode heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l].val < heap[smallest].val) smallest = l;
    if (r < n && heap[r].val < heap[smallest].val) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int main() {
    int k;
    printf("Enter number of sorted arrays: ");
    scanf("%d", &k);
    int sizes[k], total = 0;
    for (int i = 0; i < k; i++) {
        printf("Enter size of array %d: ", i+1);
        scanf("%d", &sizes[i]);
        total += sizes[i];
    }
    int *arr[k];
    for (int i = 0; i < k; i++) {
        arr[i] = malloc(sizes[i] * sizeof(int));
        printf("Enter %d sorted elements for array %d: ", sizes[i], i+1);
        for (int j = 0; j < sizes[i]; j++) scanf("%d", &arr[i][j]);
    }
    HeapNode heap[k];
    int heapSize = 0;
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            heap[heapSize].val = arr[i][0];
            heap[heapSize].arrIndex = i;
            heap[heapSize].elemIndex = 0;
            heapSize++;
        }
    }
    for (int i = heapSize/2 - 1; i >= 0; i--) heapify(heap, heapSize, i);
    int result[total], idx = 0;
    while (heapSize > 0) {
        HeapNode root = heap[0];
        result[idx++] = root.val;
        if (root.elemIndex + 1 < sizes[root.arrIndex]) {
            heap[0].val = arr[root.arrIndex][root.elemIndex+1];
            heap[0].arrIndex = root.arrIndex;
            heap[0].elemIndex = root.elemIndex+1;
        } else {
            heap[0] = heap[heapSize-1];
            heapSize--;
        }
        heapify(heap, heapSize, 0);
    }
    printf("Merged sorted array: ");
    for (int i = 0; i < total; i++) printf("%d ", result[i]);
    for (int i = 0; i < k; i++) free(arr[i]);
    return 0;
}
