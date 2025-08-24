#include <stdio.h>
#include <stdlib.h>

// Min-heap helper functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

void insertHeap(int arr[], int *n, int key) {
    arr[*n] = key;
    int i = *n;
    (*n)++;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int maxSumAfterKNegations(int nums[], int n, int k) {
    // Build min-heap
    for (int i = n / 2 - 1; i >= 0; i--) heapify(nums, n, i);

    while (k--) {
        int minVal = extractMin(nums, &n);
        minVal = -minVal;  // flip sign
        insertHeap(nums, &n, minVal);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    return sum;
}

int main() {
    int nums1[] = {4, 2, 3};
    int k1 = 1;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Input: [4,2,3], k=1 → Output: %d\n", maxSumAfterKNegations(nums1, n1, k1));

    int nums2[] = {3, -1, 0, 2};
    int k2 = 3;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Input: [3,-1,0,2], k=3 → Output: %d\n", maxSumAfterKNegations(nums2, n2, k2));

    return 0;
}
