#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
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
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    convertMinToMaxHeap(arr, n);

    printf("Converted Max Heap: ");
    printArray(arr, n);
    return 0;
}
