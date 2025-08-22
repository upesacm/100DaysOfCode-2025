#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(int heap[], int *n, int val, int k) {
    if (*n < k) {
        heap[(*n)++] = val;
        int i = *n - 1;
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(&heap[i], &heap[(i-1)/2]);
            i = (i-1)/2;
        }
    } else if (val > heap[0]) {
        heap[0] = val;
        heapify(heap, *n, 0);
    }
}

int kthLargestSubarraySum(int arr[], int n, int k) {
    int prefix[n+1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + arr[i-1];

    int heap[k];
    int size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int sum = prefix[j] - prefix[i];
            insertHeap(heap, &size, sum, k);
        }
    }
    return heap[0];
}

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int result = kthLargestSubarraySum(arr, n, k);
    printf("Kth largest subarray sum: %d\n", result);

    return 0;
}
