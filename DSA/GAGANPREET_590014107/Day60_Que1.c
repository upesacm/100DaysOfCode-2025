
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

int extractMin(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return root;
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    int i = *size - 1;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void sortKSortedArray(int arr[], int n, int k) {
    int heapSize = 0, heap[k + 1], index = 0;
    for (int i = 0; i < k + 1 && i < n; i++) {
        insertHeap(heap, &heapSize, arr[i]);
    }
    for (int i = k + 1; i < n; i++) {
        arr[index++] = extractMin(heap, &heapSize);
        insertHeap(heap, &heapSize, arr[i]);
    }
    while (heapSize > 0) {
        arr[index++] = extractMin(heap, &heapSize);
    }
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter value of k: ");
    scanf("%d", &k);

    sortKSortedArray(arr, n, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
