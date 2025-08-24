#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for heap node
typedef struct {
    int value;
    int distance;
} HeapNode;

// Structure for max-heap
typedef struct {
    HeapNode* nodes;
    int size;
    int capacity;
} MaxHeap;

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->nodes = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Heapify up
void heapifyUp(MaxHeap* heap, int index) {
    while (index > 0 && heap->nodes[parent(index)].distance < heap->nodes[index].distance) {
        swap(&heap->nodes[index], &heap->nodes[parent(index)]);
        index = parent(index);
    }
}

// Heapify down
void heapifyDown(MaxHeap* heap, int index) {
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->nodes[left].distance > heap->nodes[maxIndex].distance)
        maxIndex = left;
    if (right < heap->size && heap->nodes[right].distance > heap->nodes[maxIndex].distance)
        maxIndex = right;

    if (index != maxIndex) {
        swap(&heap->nodes[index], &heap->nodes[maxIndex]);
        heapifyDown(heap, maxIndex);
    }
}

// Insert into max-heap
void insertMaxHeap(MaxHeap* heap, int value, int distance) {
    if (heap->size < heap->capacity) {
        heap->nodes[heap->size].value = value;
        heap->nodes[heap->size].distance = distance;
        heapifyUp(heap, heap->size);
        heap->size++;
    } else if (distance < heap->nodes[0].distance) {
        heap->nodes[0].value = value;
        heap->nodes[0].distance = distance;
        heapifyDown(heap, 0);
    }
}

// Comparator for qsort
int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find k closest numbers
int* findKClosest(int arr[], int n, int target, int k, int* resultSize) {
    if (k <= 0 || n < k) {
        *resultSize = 0;
        return NULL;
    }

    MaxHeap* heap = createMaxHeap(k);

    for (int i = 0; i < n; i++) {
        int distance = abs(arr[i] - target);
        insertMaxHeap(heap, arr[i], distance);
    }

    int* result = (int*)malloc(k * sizeof(int));
    *resultSize = k;
    for (int i = 0; i < k; i++) {
        result[i] = heap->nodes[i].value;
    }

    qsort(result, k, sizeof(int), cmpInt);

    free(heap->nodes);
    free(heap);
    return result;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, k, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array must have positive size.\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter target value: ");
    scanf("%d", &target);

    printf("Enter k: ");
    scanf("%d", &k);

    int resultSize;
    int* result = findKClosest(arr, n, target, k, &resultSize);

    if (resultSize > 0) {
        printf("K Closest Numbers: ");
        printArray(result, resultSize);
        free(result);
    } else {
        printf("Invalid input: k must be > 0 and <= n\n");
    }

    free(arr);
    return 0;
}
