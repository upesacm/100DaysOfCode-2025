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

void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
    } else if (value > heap->arr[0]) {
        heap->arr[0] = value;
        heapifyDown(heap, 0);
    }
}

int* findKLargest(int arr[], int n, int k) {
    if (k <= 0 || n < k) {
        return NULL;
    }
    
    MinHeap* heap = createMinHeap(k);
    
    for (int i = 0; i < n; i++) {
        insertMinHeap(heap, arr[i]);
    }
    
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = heap->arr[i];
    }
    
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (result[j] < result[j + 1]) {
                swap(&result[j], &result[j + 1]);
            }
        }
    }
    
    free(heap->arr);
    free(heap);
    return result;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements of the array (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    int* result = findKLargest(arr, n, k);
    if (result) {
        printf("The %d largest elements are: ", k);
        printArray(result, k);
        free(result);
    } else {
        printf("Invalid input or no result.\n");
    }
    
    free(arr);
    return 0;
}
