#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int row;
    int col;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;
    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(HeapNode heap[], int i) {
    if (i && heap[(i - 1) / 2].value > heap[i].value) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        heapifyUp(heap, (i - 1) / 2);
    }
}

void push(HeapNode heap[], int *size, HeapNode node) {
    heap[(*size)++] = node;
    heapifyUp(heap, *size - 1);
}

HeapNode pop(HeapNode heap[], int *size) {
    HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

int main() {
    int k;
    printf("Enter number of sorted arrays: ");
    scanf("%d", &k);

    int arr[k][100], sizes[k]; // assume max 100 elements per array
    for (int i = 0; i < k; i++) {
        printf("Enter number of elements in array %d: ", i + 1);
        scanf("%d", &sizes[i]);
        printf("Enter elements (sorted): ");
        for (int j = 0; j < sizes[i]; j++)
            scanf("%d", &arr[i][j]);
    }

    HeapNode heap[1000];
    int heapSize = 0;
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0)
            push(heap, &heapSize, (HeapNode){arr[i][0], i, 0});
    }

    printf("Merged array: [");
    int first = 1;
    while (heapSize > 0) {
        HeapNode minNode = pop(heap, &heapSize);
        if (!first) printf(", ");
        first = 0;
        printf("%d", minNode.value);

        if (minNode.col + 1 < sizes[minNode.row])
            push(heap, &heapSize, (HeapNode){arr[minNode.row][minNode.col + 1], minNode.row, minNode.col + 1});
    }
    printf("]\n");

    return 0;
}
