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

void replaceRoot(int arr[], int n, int newElement) {
    arr[0] = newElement;
    maxHeapify(arr, n, 0);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {50, 30, 20, 15, 10, 8, 16};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int newElement1 = 25;
    replaceRoot(arr1, n1, newElement1);
    printArray(arr1, n1);

    int arr2[] = {100, 80, 70, 60, 50, 40, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int newElement2 = 35;
    replaceRoot(arr2, n2, newElement2);
    printArray(arr2, n2);

    return 0;
}
