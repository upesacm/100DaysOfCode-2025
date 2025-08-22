#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

int extractMin(int arr[], int *n) {
    if (*n <= 0) return INT_MAX;
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}

int kthSmallest(int arr[], int n, int k) {
    buildMinHeap(arr, n);
    for (int i = 1; i < k; i++)
        extractMin(arr, &n);
    return arr[0]; 
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Kth smallest: %d\n", kthSmallest(arr, n, k));
    return 0;
}

