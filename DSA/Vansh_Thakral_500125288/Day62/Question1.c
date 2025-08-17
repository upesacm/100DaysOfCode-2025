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
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0 && heap->arr[(idx-1)/2] > heap->arr[idx]) {
        swap(&heap->arr[idx], &heap->arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1, right = 2*idx + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MinHeap* heap, int val) {
    heap->arr[heap->size] = val;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap* heap) {
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

int connectRopes(int ropes[], int n) {
    MinHeap* heap = createHeap(n);
    for (int i = 0; i < n; i++) insert(heap, ropes[i]);

    int totalCost = 0;
    while (heap->size > 1) {
        int first = extractMin(heap);
        int second = extractMin(heap);
        int cost = first + second;
        totalCost += cost;
        insert(heap, cost);
    }
    return totalCost;
}

int main() {
    int arr1[] = {4, 3, 2, 6};
    int n1 = 4;
    printf("Minimum cost: %d\n", connectRopes(arr1, n1)); 

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = 5;
    printf("Minimum cost: %d\n", connectRopes(arr2, n2)); 
    return 0;
}
  
