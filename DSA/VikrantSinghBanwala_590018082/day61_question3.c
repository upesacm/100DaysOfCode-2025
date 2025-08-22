#include <stdio.h>

void siftDown(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        siftDown(arr, n, largest);
    }
}

void heapify(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    heapify(arr, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        siftDown(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {4, 10, 3, 5, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    heapSort(arr1, n1);
    printf("Sorted array: ");
    printArray(arr1, n1);

    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    heapSort(arr2, n2);
    printf("Sorted array: ");
    printArray(arr2, n2);

    return 0;
}
