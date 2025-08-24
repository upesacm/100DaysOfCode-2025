#include <stdio.h>
#include <stdlib.h>

// Structure for min-heap
typedef struct {
    long long* arr;
    int size;
    int capacity;
} MinHeap;

// Function to create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (long long*)malloc(capacity * sizeof(long long));
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

// Heapify up
void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->arr[parent(index)] > heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[parent(index)]);
        index = parent(index);
    }
}

// Heapify down
void heapifyDown(MinHeap* heap, int index) {
    int minIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap->size && heap->arr[left] < heap->arr[minIndex]) {
        minIndex = left;
    }
    if (right < heap->size && heap->arr[right] < heap->arr[minIndex]) {
        minIndex = right;
    }
    if (index != minIndex) {
        swap(&heap->arr[index], &heap->arr[minIndex]);
        heapifyDown(heap, minIndex);
    }
}

// Insert into heap
void insertMinHeap(MinHeap* heap, long long value) {
    if (heap->size >= heap->capacity) return;
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract minimum
long long extractMin(MinHeap* heap) {
    if (heap->size == 0) return -1;
    long long min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

// Main function to calculate min cost
long long minCostToConnectRopes(long long ropes[], int n) {
    if (n <= 1) return 0;

    MinHeap* heap = createMinHeap(n);
    for (int i = 0; i < n; i++) {
        insertMinHeap(heap, ropes[i]);
    }

    long long totalCost = 0;
    while (heap->size > 1) {
        long long first = extractMin(heap);
        long long second = extractMin(heap);
        long long combined = first + second;
        totalCost += combined;
        insertMinHeap(heap, combined);
    }

    free(heap->arr);
    free(heap);
    return totalCost;
}

int main() {
    int n;
    printf("Enter number of ropes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Output: 0\n");
        return 0;
    }

    long long* ropes = (long long*)malloc(n * sizeof(long long));
    printf("Enter rope lengths: ");
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ropes[i]);
    }

    long long result = minCostToConnectRopes(ropes, n);
    printf("Minimum Cost: %lld\n", result);

    free(ropes);
    return 0;
}
