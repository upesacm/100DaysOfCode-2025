#include <stdio.h>

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify for Min-Heap
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

// Function to find K largest elements
void kLargest(int arr[], int n, int k) {
    if (k > n) k = n; // Handle case where k > n

    // Step 1: Build Min-Heap with first k elements
    int heap[k];
    for (int i = 0; i < k; i++)
        heap[i] = arr[i];

    for (int i = k / 2 - 1; i >= 0; i--)
        minHeapify(heap, k, i);

    // Step 2: Process remaining elements
    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];      // Replace root
            minHeapify(heap, k, 0); // Heapify again
        }
    }

    // Step 3: Output k largest elements (heap contains them)
    // Optional: Sort them in descending order before printing
    for (int i = k - 1; i >= 0; i--) {
        swap(&heap[0], &heap[i]);
        minHeapify(heap, i, 0);
    }

    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%d", heap[i]);
        if (i < k - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    printf("Example 1 Output: ");
    kLargest(arr1, n1, k1);

    int arr2[] = {10, 15, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 2;
    printf("Example 2 Output: ");
    kLargest(arr2, n2, k2);

    return 0;
}
