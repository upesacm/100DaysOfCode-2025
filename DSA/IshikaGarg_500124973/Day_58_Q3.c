#include <stdio.h>

// Swap helper function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heapify function
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

// Replace root and restore heap property
void replaceRoot(int arr[], int n, int newElement) {
    printf("Replacing root %d with %d\n", arr[0], newElement);
    arr[0] = newElement;
    maxHeapify(arr, n, 0);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr1[] = {50, 30, 20, 15, 10, 8, 16};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int new1 = 25;

    printf("Original Heap: ");
    printArray(arr1, n1);
    replaceRoot(arr1, n1, new1);
    printf("New Heap: ");
    printArray(arr1, n1);

    printf("\n");

    int arr2[] = {100, 80, 70, 60, 50, 40, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int new2 = 35;

    printf("Original Heap: ");
    printArray(arr2, n2);
    replaceRoot(arr2, n2, new2);
    printf("New Heap: ");
    printArray(arr2, n2);

    return 0;
}

