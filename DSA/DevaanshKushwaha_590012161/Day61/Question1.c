#include <stdio.h>

// Utility swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify function for Max Heap (sift-down)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to convert Min Heap → Max Heap
void convertToMaxHeap(int arr[], int n) {
    // Start from last non-leaf node
    for (int i = (n/2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {
    int n;
    printf("Enter size of heap: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of Min Heap: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    convertToMaxHeap(arr, n);

    printf("Converted Max Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
