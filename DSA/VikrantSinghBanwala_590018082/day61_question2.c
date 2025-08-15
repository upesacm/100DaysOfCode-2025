#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int*)malloc(capacity * sizeof(int));
    return heap;
}

void bubbleUp(MaxHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[index] <= heap->arr[parent]) {
            break;
        }
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[parent];
        heap->arr[parent] = temp;
        index = parent;
    }
}

void insert(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->arr[heap->size] = value;
    bubbleUp(heap, heap->size);
    heap->size++;
}

void siftDown(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        siftDown(heap, largest);
    }
}

int deleteRoot(MaxHeap* heap) {
    if (heap->size == 0) {
        return -1; // Heap is empty
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    siftDown(heap, 0);
    return root;
}

void printHeap(MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void freeHeap(MaxHeap* heap) {
    free(heap->arr);
    free(heap);
}

int main() {
    MaxHeap* heap = createHeap(10);
    
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 8);
    printf("Heap after insertions: ");
    printHeap(heap);
    
    deleteRoot(heap);
    printf("Heap after deleting root: ");
    printHeap(heap);
    
    insert(heap, 30);
    insert(heap, 25);
    insert(heap, 10);
    insert(heap, 35);
    printf("Heap after more insertions: ");
    printHeap(heap);
    
    deleteRoot(heap);
    printf("Heap after deleting root: ");
    printHeap(heap);
    
    insert(heap, 40);
    printf("Heap after inserting 40: ");
    printHeap(heap);
    
    freeHeap(heap);
    return 0;
}
