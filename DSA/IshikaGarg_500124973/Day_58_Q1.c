#include <stdio.h>

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify function
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

// Function to find Kth smallest element
int kthSmallest(int arr[], int n, int k) {
    // Step 1: Build min-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Step 2: Extract min k times
    for (int i = 0; i < k - 1; i++) {
        // Replace root with last element
        arr[0] = arr[n - 1];
        n--; // Reduce heap size
        minHeapify(arr, n, 0);
    }

    // Root is now Kth smallest
    return arr[0];
}

// Driver Code
int main() {
    int arr1[] = {7, 10, 4, 3, 20, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    printf("Example 1 Output: %d\n", kthSmallest(arr1, n1, k1));

    int arr2[] = {7, 10, 4, 20, 15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 4;
    printf("Example 2 Output: %d\n", kthSmallest(arr2, n2, k2));

    return 0;
}

