#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
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

void kLargest(int arr[], int n, int k) {
    if (k > n) k = n;

    int heap[k];
    for (int i = 0; i < k; i++) heap[i] = arr[i];

    for (int i = k / 2 - 1; i >= 0; i--) heapify(heap, k, i);

    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            heapify(heap, k, 0);
        }
    }

    // Output
    for (int i = 0; i < k; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

