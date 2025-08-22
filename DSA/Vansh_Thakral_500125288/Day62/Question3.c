#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx+1, right = 2*idx+2;
    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0 && heap->arr[(idx-1)/2] > heap->arr[idx]) {
        swap(&heap->arr[idx], &heap->arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

void push(MinHeap* heap, int val) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size] = val;
        heap->size++;
        heapifyUp(heap, heap->size-1);
    } else if (val > heap->arr[0]) {
        heap->arr[0] = val;
        heapifyDown(heap, 0);
    }
}

int kthLargestSubarraySum(int arr[], int n, int k) {
    MinHeap* heap = createHeap(k);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            push(heap, sum);
        }
    }
    return heap->arr[0];
}

int main() {
    int arr1[] = {10, -10, 20, -40};
    printf("Kth Largest Sum: %d\n", kthLargestSubarraySum(arr1, 4, 3)); 

    int arr2[] = {1, 2, 3};
    printf("Kth Largest Sum: %d\n", kthLargestSubarraySum(arr2, 3, 2)); 
    return 0;
}
 
