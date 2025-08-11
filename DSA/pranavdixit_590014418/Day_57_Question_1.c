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

void kLargest(int arr[], int n, int k) {
    int heap[k];
    for (int i = 0; i < k; i++)
        heap[i] = arr[i];

    buildMinHeap(heap, k);

    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            heapify(heap, k, 0);
        }
    }

    printf("Top %d elements: ", k);
    for (int i = 0; i < k; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    kLargest(arr, n, k);
    return 0;
}
