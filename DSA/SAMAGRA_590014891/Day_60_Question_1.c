#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void kSortedSort(int arr[], int n, int k) {
    int *heap = (int*)malloc((k + 1) * sizeof(int));
    int heapSize = 0, index = 0;
    
    for (int i = 0; i < k + 1 && i < n; i++)
        heap[heapSize++] = arr[i];
    buildHeap(heap, heapSize);

    for (int i = k + 1; i < n; i++) {
        arr[index++] = heap[0];
        heap[0] = arr[i];
        heapify(heap, heapSize, 0);
    }

    while (heapSize > 0) {
        arr[index++] = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapify(heap, heapSize, 0);
    }
    free(heap);
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    kSortedSort(arr, n, k);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
