#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void minHeapify(int arr[], int n, int i) {
    int l = 2*i+1, r = 2*i+2, smallest = i;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) { swap(&arr[i], &arr[smallest]); minHeapify(arr, n, smallest); }
}

int kthSmallest(int arr[], int n, int k) {
    for (int i = n/2 - 1; i >= 0; i--) minHeapify(arr, n, i);
    for (int i = 0; i < k-1; i++) { arr[0] = arr[n-1-i]; n--; minHeapify(arr, n, 0); }
    return arr[0];
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15}, k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", kthSmallest(arr, n, k));
}
