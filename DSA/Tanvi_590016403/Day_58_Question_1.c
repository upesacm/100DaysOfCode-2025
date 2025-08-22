#include <stdio.h>

// ======== Helper functions for Heap ========

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ======== Min-Heap operations (for Kth smallest) ========

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

int extractMin(int arr[], int *n) {
    if (*n <= 0) return -1;
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}

int kthSmallest(int arr[], int n, int k) {
    buildMinHeap(arr, n);
    for (int i = 1; i < k; i++) {
        extractMin(arr, &n);
    }
    return extractMin(arr, &n);
}

// ======== Max-Heap operations (for heapify & replace root) ========

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

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void replaceRootMaxHeap(int arr[], int n, int newElement) {
    if (n <= 0) return;
    arr[0] = newElement;
    maxHeapify(arr, n, 0);
}

// ======== Utility to print array ========
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ======== Main Program ========
int main() {
    // 1. Kth Smallest Element (Min-Heap)
    int arr1[] = {7, 10, 4, 3, 20, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    printf("Kth smallest element: %d\n", kthSmallest(arr1, n1, k));

    // 2. Heapify into Max-Heap
    int arr2[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    buildMaxHeap(arr2, n2);
    printf("Max-Heap array: ");
    printArray(arr2, n2);

    // 3. Replace Root in Max-Heap
    int arr3[] = {50, 30, 20, 15, 10, 8, 16};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    replaceRootMaxHeap(arr3, n3, 25);
    printf("Heap after replacing root: ");
    printArray(arr3, n3);

    return 0;
}
