#include <stdio.h>
#include <stdbool.h>

// Function to check if array is a Max Heap
bool isMaxHeap(int arr[], int n) {
    // Only need to check for non-leaf nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] < arr[left])
            return false;

        // Check right child
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

int main() {
    int arr1[] = {90, 15, 10, 7, 12, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Example 1 Output: %s\n", isMaxHeap(arr1, n1) ? "true" : "false");

    int arr2[] = {9, 15, 10, 7, 12, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Example 2 Output: %s\n", isMaxHeap(arr2, n2) ? "true" : "false");

    return 0;
}

