#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleUp(int arr[], int i) {
    while (i > 0 && arr[(i-1)/2] < arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void siftDown(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        siftDown(arr, n, largest);
    }
}

int insert(int arr[], int n, int val) {
    arr[n] = val;
    bubbleUp(arr, n);
    return n+1;
}

int deleteRoot(int arr[], int n) {
    if (n <= 0) return n;
    arr[0] = arr[n-1];
    siftDown(arr, n-1, 0);
    return n-1;
}

int main() {
    int arr[100], n = 0;
    n = insert(arr, n, 20);
    n = insert(arr, n, 15);
    n = insert(arr, n, 8);
    n = deleteRoot(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    n = 0;
    n = insert(arr, n, 30);
    n = insert(arr, n, 25);
    n = insert(arr, n, 10);
    n = insert(arr, n, 35);
    n = deleteRoot(arr, n);
    n = insert(arr, n, 40);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
