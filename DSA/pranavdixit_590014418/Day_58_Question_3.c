#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void replaceRoot(int arr[], int n, int newVal) {
    arr[0] = newVal;
    maxHeapify(arr, n, 0);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {50, 30, 20, 15, 10, 8, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newElement = 25;

    replaceRoot(arr, n, newElement);
    printArray(arr, n); // Output: new heap with root replaced
    return 0;
}
