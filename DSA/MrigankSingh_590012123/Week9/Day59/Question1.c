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

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

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

void insert(MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        printf("Error: Heap is full. Cannot insert %d.\n", value);
        return;
    }
    
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Error: Heap is empty. Cannot extract minimum.\n");
        return -1;
    }
    
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

int isValidMinHeap(MinHeap* heap) {
    for (int i = 0; i <= (heap->size - 2) / 2; i++) {
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap->size && heap->arr[i] > heap->arr[left]) {
            return 0;
        }
        
        if (right < heap->size && heap->arr[i] > heap->arr[right]) {
            return 0;
        }
    }
    return 1;
}

void printHeap(MinHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void freeMinHeap(MinHeap* heap) {
    free(heap->arr);
    free(heap);
}

int main() {
    int capacity, choice, value;
    
    printf("Enter the initial capacity of the heap: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0) {
        printf("Error: Capacity must be positive.\n");
        return 1;
    }
    
    MinHeap* heap = createMinHeap(capacity);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Extract Minimum\n");
        printf("3. Print Heap\n");
        printf("4. Check Heap Validity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(heap, value);
                break;
            case 2:
                value = extractMin(heap);
                if (value != -1) {
                    printf("Extracted minimum: %d\n", value);
                }
                break;
            case 3:
                printHeap(heap);
                break;
            case 4:
                if (isValidMinHeap(heap)) {
                    printf("The heap is valid.\n");
                } else {
                    printf("The heap is not valid.\n");
                }
                break;
            case 5:
                freeMinHeap(heap);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
