#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void insertHeap(int* heap, int* size, int value, int k) {
    if (*size < k) {
        heap[*size] = value;
        (*size)++;
        
        for (int i = (*size / 2) - 1; i >= 0; i--) {
            minHeapify(heap, *size, i);
        }
    } else if (value > heap[0]) {
        heap[0] = value;
        minHeapify(heap, *size, 0);
    }
}

void heapSort(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(arr, size, i);
    }
    
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    int* heap = (int*)malloc(k * sizeof(int));
    int heapSize = 0;
    
    for (int i = 0; i < n; i++) {
        insertHeap(heap, &heapSize, arr[i], k);
    }
    
    heapSort(heap, heapSize);
    
    for (int i = heapSize - 1; i >= 0; i--) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    
    free(arr);
    free(heap);
    return 0;
}
