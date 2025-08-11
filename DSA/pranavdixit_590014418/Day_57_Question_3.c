#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value, row, col;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a; *a = *b; *b = temp;
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
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void mergeKSortedArrays(int **arr, int k, int n) {
    HeapNode heap[k];
    int *output = (int *)malloc(k * n * sizeof(int));
    int index = 0;

    for (int i = 0; i < k; i++) {
        heap[i].value = arr[i][0];
        heap[i].row = i;
        heap[i].col = 0;
    }

    for (int i = k / 2 - 1; i >= 0; i--)
        heapify(heap, k, i);

    while (index < k * n) {
        HeapNode root = heap[0];
        output[index++] = root.value;

        if (root.col + 1 < n) {
            heap[0].value = arr[root.row][root.col + 1];
            heap[0].col++;
        } else {
            heap[0].value = __INT_MAX__;
        }
        heapify(heap, k, 0);
    }

    printf("Merged array: ");
    for (int i = 0; i < k * n; i++)
        printf("%d ", output[i]);
    printf("\n");

    free(output);
}

int main() {
    int a1[] = {1, 3}, a2[] = {2, 4}, a3[] = {5, 6};
    int *arr[] = {a1, a2, a3};

    mergeKSortedArrays(arr, 3, 2);
    return 0;
}
