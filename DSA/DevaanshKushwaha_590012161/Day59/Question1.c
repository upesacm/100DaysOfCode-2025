#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[index] >= heap->arr[parent]) {
            break;
        }
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
    }
}

void bubbleDown(MinHeap* heap, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
            smallest = left;
        }
        
        if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
            smallest = right;
        }
        
        if (smallest == index) {
            break;
        }
        
        swap(&heap->arr[index], &heap->arr[smallest]);
        index = smallest;
    }
}

void insert(MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        return;
    }
    
    heap->arr[heap->size] = value;
    bubbleUp(heap, heap->size);
    heap->size++;
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        bubbleDown(heap, 0);
    }
    
    return min;
}

int main() {
    MinHeap* heap = createMinHeap(100);
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char op;
        scanf(" %c", &op);
        
        if (op == 'i') {
            int value;
            scanf("%d", &value);
            insert(heap, value);
        } else if (op == 'e') {
            int min = extractMin(heap);
            printf("%d ", min);
        }
    }
    
    printf("\n");
    
    free(heap->arr);
    free(heap);
    return 0;
}
