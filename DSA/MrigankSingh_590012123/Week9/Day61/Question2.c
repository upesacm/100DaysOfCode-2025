#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void resizeHeap(MaxHeap* heap) {
    heap->capacity *= 2;
    heap->arr = (int*)realloc(heap->arr, heap->capacity * sizeof(int));
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

void heapifyUp(MaxHeap* heap, int index) {
    while (index > 0 && heap->arr[parent(index)] < heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[parent(index)]);
        index = parent(index);
    }
}

void heapifyDown(MaxHeap* heap, int index) {
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap->size && heap->arr[left] > heap->arr[maxIndex]) {
        maxIndex = left;
    }
    
    if (right < heap->size && heap->arr[right] > heap->arr[maxIndex]) {
        maxIndex = right;
    }
    
    if (index != maxIndex) {
        swap(&heap->arr[index], &heap->arr[maxIndex]);
        heapifyDown(heap, maxIndex);
    }
}

void insert(MaxHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        resizeHeap(heap);
    }
    
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void deleteRoot(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return;
    }
    
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
}

void printHeap(MaxHeap* heap) {
    printf("[");
    for (int i = 0; i < heap->size; i++) {
        printf("%d", heap->arr[i]);
        if (i < heap->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void freeMaxHeap(MaxHeap* heap) {
    free(heap->arr);
    free(heap);
}

void processUserOperations(MaxHeap* heap) {
    char input[100];
    int value;
    
    while (true) {
        printf("\nEnter operation (insert <value>, delete, print, exit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        
        if (strncmp(input, "insert", 6) == 0) {
            if (sscanf(input + 7, "%d", &value) == 1) {
                insert(heap, value);
                printf("Inserted %d into the heap.\n", value);
            } else {
                printf("Invalid insert command. Usage: insert <value>\n");
            }
        } else if (strcmp(input, "delete") == 0) {
            deleteRoot(heap);
            printf("Deleted root from the heap.\n");
        } else if (strcmp(input, "print") == 0) {
            printf("Current heap: ");
            printHeap(heap);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Available commands: insert <value>, delete, print, exit\n");
        }
    }
}

int main() {
    int initialCapacity;
    printf("Enter initial capacity of the heap: ");
    scanf("%d", &initialCapacity);
    while (getchar() != '\n');
    
    MaxHeap* heap = createMaxHeap(initialCapacity);
    processUserOperations(heap);
    freeMaxHeap(heap);
    
    return 0;
}
