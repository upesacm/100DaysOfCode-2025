
#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
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
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    buildMaxHeap(arr1, n1);
    printArray(arr1, n1);

    int arr2[] = {1, 3, 6, 5, 9, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    buildMaxHeap(arr2, n2);
    printArray(arr2, n2);

    return 0;
}
