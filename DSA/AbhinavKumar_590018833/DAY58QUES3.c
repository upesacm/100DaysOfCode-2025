#include <stdio.h>

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to restore the max-heap property starting from index i
void siftDown(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively sift down
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        siftDown(arr, n, largest);
    }
}

/**
 * Replaces the root of the heap with a new element and restores the property.
 */
void replaceRoot(int arr[], int n, int newElement) {
    if (n <= 0) {
        return;
    }
    // Step 1: Replace the root
    arr[0] = newElement;

    // Step 2: Restore the heap property
    siftDown(arr, n, 0);
}

// Helper function to print an array
void printArray(const char* label, int arr[], int n) {
    printf("%s", label);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // --- Example 1 ---
    int arr1[] = {50, 30, 20, 15, 10, 8, 16};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int newElement1 = 25;
    
    printArray("Original Heap 1: ", arr1, n1);
    replaceRoot(arr1, n1, newElement1);
    printf("Heap after replacing root with %d:\n", newElement1);
    printArray("Result:          ", arr1, n1);
    printf("\n");

    // --- Example 2 ---
    int arr2[] = {100, 80, 70, 60, 50, 40, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int newElement2 = 35;

    printArray("Original Heap 2: ", arr2, n2);
    replaceRoot(arr2, n2, newElement2);
    printf("Heap after replacing root with %d:\n", newElement2);
    printArray("Result:          ", arr2, n2);

    return 0;
}