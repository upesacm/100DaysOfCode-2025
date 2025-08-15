#include <stdio.h>
#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void insertMaxHeap(int arr[], int *n, int value) {
    (*n)++;
    int i = *n - 1;
    arr[i] = value;

    while (i != 0 && arr[(i-1)/2] < arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteRootMaxHeap(int arr[], int *n) {
    if (*n <= 0) return;
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int heap[MAX];
    int n = 0;

    insertMaxHeap(heap, &n, 20);
    insertMaxHeap(heap, &n, 15);
    insertMaxHeap(heap, &n, 8);
    printf("Heap after insertions: ");
    printHeap(heap, n);

    deleteRootMaxHeap(heap, &n);
    printf("Heap after deleting root: ");
    printHeap(heap, n);

    insertMaxHeap(heap, &n, 30);
    insertMaxHeap(heap, &n, 25);
    insertMaxHeap(heap, &n, 10);
    insertMaxHeap(heap, &n, 35);
    deleteRootMaxHeap(heap, &n);
    insertMaxHeap(heap, &n, 40);

    printf("Heap after more operations: ");
    printHeap(heap, n);

    return 0;
}

