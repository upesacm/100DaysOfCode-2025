#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int capacity;
    int size;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
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

void bubbleUp(MaxHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[index] <= heap->arr[parent]) {
            break;
        }
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
    }
}

void bubbleDown(MaxHeap* heap, int index) {
    while (1) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
            largest = left;
        }
        
        if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
            largest = right;
        }
        
        if (largest == index) {
            break;
        }
        
        swap(&heap->arr[index], &heap->arr[largest]);
        index = largest;
    }
}

void insert(MaxHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        return;
    }
    
    heap->arr[heap->size] = value;
    bubbleUp(heap, heap->size);
    heap->size++;
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        bubbleDown(heap, 0);
    }
    
    return max;
}

int main() {
    MaxHeap* heap = createMaxHeap(100);
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
            int max = extractMax(heap);
            printf("%d ", max);
        }
    }
    
    printf("\n");
    
    free(heap->arr);
    free(heap);
    return 0;
}
