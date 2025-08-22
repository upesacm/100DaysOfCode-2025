#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void maxHeapify(int arr[], int n, int i) {
    int l = 2*i+1, r = 2*i+2, largest = i;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); maxHeapify(arr, n, largest); }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildMaxHeap(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}
