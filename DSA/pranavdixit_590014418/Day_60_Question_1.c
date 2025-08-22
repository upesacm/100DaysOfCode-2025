#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void sortKSortedArray(int arr[], int n, int k) {
    int *heap = (int *)malloc((k + 1) * sizeof(int));
    int heapSize = 0, idx = 0;

    for (int i = 0; i < k + 1 && i < n; i++)
        heap[heapSize++] = arr[i];
    buildMinHeap(heap, heapSize);

    for (int i = k + 1; i < n; i++) {
        arr[idx++] = heap[0];
        heap[0] = arr[i];
        heapify(heap, heapSize, 0);
    }

    while (heapSize > 0) {
        arr[idx++] = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapify(heap, heapSize, 0);
    }
    free(heap);
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    sortKSortedArray(arr, n, k);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); // Output: 2 3 5 6 8 9 10
    printf("\n");
    return 0;
}
