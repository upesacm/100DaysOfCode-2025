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

void convertMinToMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(arr, n, i);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    convertMinToMaxHeap(arr1, n1);
    printHeap(arr1, n1);

    int arr2[] = {2, 4, 6, 8, 10, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    convertMinToMaxHeap(arr2, n2);
    printHeap(arr2, n2);

    return 0;
}
