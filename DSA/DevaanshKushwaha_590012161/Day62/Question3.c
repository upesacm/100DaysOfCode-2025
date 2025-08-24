#include <stdio.h>
#include <stdlib.h>

// Min-heap functions
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

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

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    int i = *n - 1;
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void removeMin(int heap[], int *n) {
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
}

// Function to find kth largest subarray sum
int kthLargestSubarraySum(int arr[], int n, int k) {
    int prefix[n+1];
    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i+1] = prefix[i] + arr[i];

    int heap[n*n];  
    int heapSize = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int sum = prefix[i] - prefix[j];

            if (heapSize < k) {
                insertHeap(heap, &heapSize, sum);
            } else if (sum > heap[0]) {
                heap[0] = sum;
                minHeapify(heap, heapSize, 0);
            }
        }
    }

    return heap[0];
}

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int result = kthLargestSubarraySum(arr, n, k);
    printf("Kth largest subarray sum = %d\n", result);

    return 0;
}
