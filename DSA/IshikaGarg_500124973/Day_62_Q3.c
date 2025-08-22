#include <stdio.h>
#include <stdlib.h>

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyDownInt(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swapInt(&heap[i], &heap[smallest]);
        heapifyDownInt(heap, n, smallest);
    }
}

void heapifyUpInt(int heap[], int i) {
    int parent = (i-1)/2;
    if (i > 0 && heap[i] < heap[parent]) {
        swapInt(&heap[i], &heap[parent]);
        heapifyUpInt(heap, parent);
    }
}

void insertMinHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    heapifyUpInt(heap, *n - 1);
}

void replaceMin(int heap[], int n, int val) {
    heap[0] = val;
    heapifyDownInt(heap, n, 0);
}

int kthLargestSubarraySum(int arr[], int size, int k) {
    int prefix[size+1];
    prefix[0] = 0;
    for (int i = 0; i < size; i++)
        prefix[i+1] = prefix[i] + arr[i];
    
    int heap[1000]; // store k elements
    int n = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j <= size; j++) {
            int curr_sum = prefix[j] - prefix[i];
            
            if (n < k) {
                insertMinHeap(heap, &n, curr_sum);
            } else if (curr_sum > heap[0]) {
                replaceMin(heap, n, curr_sum);
            }
        }
    }
    
    return heap[0];
}

int main() {
    int arr1[] = {10, -10, 20, -40};
    printf("%d\n", kthLargestSubarraySum(arr1, 4, 3)); // 10
    
    int arr2[] = {1, 2, 3};
    printf("%d\n", kthLargestSubarraySum(arr2, 3, 2)); // 5
    return 0;
}
