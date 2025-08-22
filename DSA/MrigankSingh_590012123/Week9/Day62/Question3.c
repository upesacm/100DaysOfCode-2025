#include <stdio.h>
#include <stdlib.h>

// Structure for min-heap
typedef struct {
    long long* arr; 
    int size;
    int capacity;
} MinHeap;

// Create min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    if (!heap) return NULL;
    heap->arr = (long long*)malloc(capacity * sizeof(long long));
    if (!heap->arr) {
        free(heap);
        return NULL;
    }
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(long long* a, long long* b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->arr[parent(index)] > heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[parent(index)]);
        index = parent(index);
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int minIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->arr[left] < heap->arr[minIndex])
        minIndex = left;

    if (right < heap->size && heap->arr[right] < heap->arr[minIndex])
        minIndex = right;

    if (index != minIndex) {
        swap(&heap->arr[index], &heap->arr[minIndex]);
        heapifyDown(heap, minIndex);
    }
}

void insertMinHeap(MinHeap* heap, long long value) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
    } else if (value > heap->arr[0]) {
        heap->arr[0] = value;
        heapifyDown(heap, 0);
    }
}

// Function to find kth largest subarray sum
long long findKthLargestSubarraySum(int arr[], int n, int k) {
    if (n <= 0 || k <= 0) return -1;

    int totalSubarrays = (n * (n + 1)) / 2;
    if (k > totalSubarrays) return -1;

    MinHeap* heap = createMinHeap(k);
    if (!heap) return -1;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            insertMinHeap(heap, sum);
        }
    }

    long long result = heap->arr[0];
    free(heap->arr);
    free(heap);
    return result;
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    long long result = findKthLargestSubarraySum(arr, n, k);
    if (result == -1) {
        printf("Invalid input or k too large.\n");
    } else {
        printf("Kth Largest Subarray Sum: %lld\n", result);
    }

    free(arr);
    return 0;
}
