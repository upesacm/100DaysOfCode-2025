#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void kSortedArray(int arr[], int n, int k) {
    int *heap = (int *)malloc((k + 1) * sizeof(int));
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        heap[heapSize++] = arr[i];
        if (heapSize > k) {
            buildMinHeap(heap, heapSize);
            arr[i - k] = heap[0];
            heap[0] = heap[heapSize - 1];
            heapSize--;
            minHeapify(heap, heapSize, 0);
        }
    }

    while (heapSize > 0) {
        buildMinHeap(heap, heapSize);
        arr[n - heapSize] = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        minHeapify(heap, heapSize, 0);
    }

    free(heap);
}

int main() {
    int arr1[] = {6, 5, 3, 2, 8, 10, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    kSortedArray(arr1, n1, k1);
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int arr2[] = {3, 2, 1, 5, 4, 7, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;
    kSortedArray(arr2, n2, k2);
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
