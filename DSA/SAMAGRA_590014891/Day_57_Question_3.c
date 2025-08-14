#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value, row, col;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a; *a = *b; *b = t;
}

void heapify(HeapNode heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && heap[l].value < heap[smallest].value) smallest = l;
    if (r < n && heap[r].value < heap[smallest].value) smallest = r;
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
        printf("Enter size of array %d: ", i + 1);
        scanf("%d", &sizes[i]);
        total += sizes[i];
    }

    int *arr[k];
    for (int i = 0; i < k; i++) {
        arr[i] = (int *)malloc(sizes[i] * sizeof(int));
        printf("Enter sorted elements of array %d: ", i + 1);
        for (int j = 0; j < sizes[i]; j++) scanf("%d", &arr[i][j]);
    }

    HeapNode heap[k];
    int heapSize = 0;
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            heap[heapSize].value = arr[i][0];
            heap[heapSize].row = i;
            heap[heapSize].col = 0;
            heapSize++;
        }
    }

    for (int i = heapSize / 2 - 1; i >= 0; i--) heapify(heap, heapSize, i);

    printf("Merged array: ");
    for (int count = 0; count < total; count++) {
        HeapNode root = heap[0];
        printf("%d ", root.value);

        if (root.col + 1 < sizes[root.row]) {
            heap[0].value = arr[root.row][root.col + 1];
            heap[0].row = root.row;
            heap[0].col = root.col + 1;
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }
        heapify(heap, heapSize, 0);
    }
    return 0;
}
