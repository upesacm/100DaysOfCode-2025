#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Build min-heap
void buildMinHeap(int heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

// Extract min from heap
int extractMin(int heap[], int *n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
    return min;
}

// Sort k-sorted array
void sortKSortedArray(int arr[], int n, int k) {
    int heapSize = (k + 1 < n) ? (k + 1) : n;
    int heap[heapSize];

    for (int i = 0; i < heapSize; i++)
        heap[i] = arr[i];

    buildMinHeap(heap, heapSize);

    int index = 0;
    for (int i = heapSize; i < n; i++) {
        arr[index++] = extractMin(heap, &heapSize);
        heap[heapSize++] = arr[i];
        int j = heapSize - 1;
        while (j > 0 && heap[(j - 1) / 2] > heap[j]) {
            swap(&heap[(j - 1) / 2], &heap[j]);
            j = (j - 1) / 2;
        }
    }

    while (heapSize > 0)
        arr[index++] = extractMin(heap, &heapSize);
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    sortKSortedArray(arr, n, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
