#include <stdio.h>
#include <stdlib.h>

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

void heapifyUp(MaxHeap* heap, int index) {
    while (index > 0 && heap->arr[parent(index)] < heap->arr[index]) {
        swap(&heap->arr[parent(index)], &heap->arr[index]);
        index = parent(index);
    }
}

void insertMaxHeap(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMax(MaxHeap* heap) {
    if (heap->size == 0) {
        return -1; 
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

int findKthSmallest(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        return -1;
    }
    
    MaxHeap* heap = createMaxHeap(k);
    
    for (int i = 0; i < k; i++) {
        insertMaxHeap(heap, arr[i]);
    }
    
    for (int i = k; i < n; i++) {
        if (arr[i] < heap->arr[0]) {
            heap->arr[0] = arr[i];
            heapifyDown(heap, 0);
        }
    }
    
    int result = heap->arr[0];
    
    free(heap->arr);
    free(heap);
    return result;
}

int main() {
    int n, k;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    int result = findKthSmallest(arr, n, k);
    if (result == -1) {
        printf("Invalid value of k.\n");
    } else {
        printf("The %dth smallest element is: %d\n", k, result);
    }
    
    free(arr);
    return 0;
}
