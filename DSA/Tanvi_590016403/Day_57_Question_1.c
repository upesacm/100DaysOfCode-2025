#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ========================== HEAP UTILITIES ==========================
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Build Min Heap
void buildMinHeap(int heap[], int n) {
    for (int i = (n/2) - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

// ==================== 1. K LARGEST ELEMENTS ====================
void kLargestElements(int arr[], int n, int k) {
    int heap[k];
    for (int i = 0; i < k; i++)
        heap[i] = arr[i];

    buildMinHeap(heap, k);

    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            minHeapify(heap, k, 0);
        }
    }

    printf("K Largest Elements: ");
    for (int i = 0; i < k; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// ==================== 2. IS ARRAY A MAX HEAP ====================
bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[i] < arr[left])
            return false;
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

// ==================== 3. MERGE K SORTED ARRAYS ====================
typedef struct {
    int value;
    int row;
    int col;
} HeapNode;

void minHeapifyMerge(HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left].value < heap[smallest].value)
        smallest = left;
    if (right < n && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        HeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapifyMerge(heap, n, smallest);
    }
}

void mergeKSortedArrays(int arr[][100], int k, int n) {
    HeapNode heap[k];
    int result[k*n];
    int idx = 0;

    for (int i = 0; i < k; i++) {
        heap[i].value = arr[i][0];
        heap[i].row = i;
        heap[i].col = 0;
    }

    for (int i = (k/2) - 1; i >= 0; i--)
        minHeapifyMerge(heap, k, i);

    while (1) {
        HeapNode root = heap[0];
        result[idx++] = root.value;

        if (root.col + 1 < n) {
            heap[0].value = arr[root.row][root.col + 1];
            heap[0].col += 1;
        } else {
            heap[0].value = 1e9; // Sentinel value
        }

        minHeapifyMerge(heap, k, 0);

        if (heap[0].value == 1e9)
            break;
    }

    printf("Merged Array: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", result[i]);
    printf("\n");
}

// ==================== MAIN FUNCTION ====================
int main() {
    // 1. K Largest Elements
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int k1 = 3;
    kLargestElements(arr1, n1, k1);

    // 2. Is Array a Max Heap
    int arr2[] = {90, 15, 10, 7, 12, 2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Is Max Heap? %s\n", isMaxHeap(arr2, n2) ? "true" : "false");

    // 3. Merge K Sorted Arrays
    int arr3[3][100] = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6, 9}
    };
    mergeKSortedArrays(arr3, 3, 3);

    return 0;
}
