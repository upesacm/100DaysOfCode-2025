#include <stdio.h>

void heapifyDown(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyDown(arr, n, largest);
    }
}

void heapifyUp(int arr[], int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && arr[i] > arr[parent]) {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        heapifyUp(arr, parent);
    }
}

int insert(int arr[], int n, int key) {
    arr[n] = key;
    heapifyUp(arr, n);
    return n + 1;
}

int deleteRoot(int arr[], int n) {
    if (n <= 0) return n;
    arr[0] = arr[n - 1];
    n--;
    heapifyDown(arr, n, 0);
    return n;
}

int main() {
    int arr[100];
    int n = 0;

    n = insert(arr, n, 20);
    n = insert(arr, n, 15);
    n = insert(arr, n, 8);
    n = deleteRoot(arr, n);

    printf("Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
