#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void maxHeapify(int arr[], int n, int i) {
    int l = 2*i+1, r = 2*i+2, largest = i;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); maxHeapify(arr, n, largest); }
}

void replaceRoot(int arr[], int n, int val) {
    arr[0] = val;
    maxHeapify(arr, n, 0);
}

int main() {
    int arr[] = {50, 30, 20, 15, 10, 8, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    replaceRoot(arr, n, 25);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}
