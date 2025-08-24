#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(int* a, int* b) {
    int temp = *a;
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

void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        return -1;
    }
    
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

int minCostToConnectRopes(int ropes[], int n) {
    if (n <= 1) {
        return 0;
    }
    
    MinHeap* heap = createMinHeap(n);
    for (int i = 0; i < n; i++) {
        insertMinHeap(heap, ropes[i]);
    }
    
    int totalCost = 0;
    
    while (heap->size > 1) {
        int first = extractMin(heap);
        int second = extractMin(heap);
        int combined = first + second;
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
    
    int* ropes = (int*)malloc(n * sizeof(int));
    
    printf("Enter rope lengths: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ropes[i]);
    }
    
    int result = minCostToConnectRopes(ropes, n);
    printf("Minimum cost to connect ropes: %d\n", result);
    
    free(ropes);
    return 0;
}
