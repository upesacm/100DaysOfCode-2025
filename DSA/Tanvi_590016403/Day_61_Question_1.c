#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ---------- MAX HEAPIFY ----------
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

// ---------- MIN HEAPIFY ----------
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

// ---------- CONVERT MIN HEAP TO MAX HEAP ----------
void convertMinToMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// ---------- INSERT INTO MAX HEAP ----------
void insertMaxHeap(int arr[], int *n, int value) {
    arr[*n] = value;
    (*n)++;
    int i = (*n) - 1;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// ---------- DELETE ROOT FROM MAX HEAP ----------
void deleteRootMaxHeap(int arr[], int *n) {
    if (*n <= 0) return;
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
}

// ---------- HEAP SORT ----------
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// ---------- PRINT ARRAY ----------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------- MAIN FUNCTION ----------
int main() {
    // 1. Convert Min Heap to Max Heap
    int minHeap[] = {1, 3, 5, 7, 9, 2};
    int n1 = sizeof(minHeap) / sizeof(minHeap[0]);
    printf("Original Min Heap: ");
    printArray(minHeap, n1);
    convertMinToMaxHeap(minHeap, n1);
    printf("Converted to Max Heap: ");
    printArray(minHeap, n1);

    // 2. Insert and Delete in Max Heap
    int maxHeap[20];
    int n2 = 0;
    insertMaxHeap(maxHeap, &n2, 20);
    insertMaxHeap(maxHeap, &n2, 15);
    insertMaxHeap(maxHeap, &n2, 8);
    printf("Max Heap after inserts: ");
    printArray(maxHeap, n2);
    deleteRootMaxHeap(maxHeap, &n2);
    printf("Max Heap after deleting root: ");
    printArray(maxHeap, n2);

    // 3. Heap Sort
    int arr[] = {4, 10, 3, 5, 1};
    int n3 = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: ");
    printArray(arr, n3);
    heapSort(arr, n3);
    printf("Sorted Array (Heap Sort): ");
    printArray(arr, n3);

    return 0;
}
