#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->arr[(index - 1) / 2] > heap->arr[index]) {
        swap(&heap->arr[(index - 1) / 2], &heap->arr[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        fprintf(stderr, "Heap is full\n");
        return;
    }
    heap->arr[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) return INT_MAX;
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

void sortKSortedArray(int arr[], int n, int k) {
    MinHeap* heap = createMinHeap(k + 1);
    int* result = (int*)malloc(n * sizeof(int));
    int resultIndex = 0;

    for (int i = 0; i <= k && i < n; i++)
        insertMinHeap(heap, arr[i]);

    for (int i = k + 1; i < n; i++) {
        result[resultIndex++] = extractMin(heap);
        insertMinHeap(heap, arr[i]);
    }

    while (heap->size > 0)
        result[resultIndex++] = extractMin(heap);

    for (int i = 0; i < n; i++)
        arr[i] = result[i];

    free(result);
    free(heap->arr);
    free(heap);
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, k;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k value: ");
    scanf("%d", &k);
    
    if (k < 0) {
        printf("Invalid k value\n");
        free(arr);
        return 1;
    }

    printf("\nOriginal array: ");
    printArray(arr, n);

    sortKSortedArray(arr, n, k);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
