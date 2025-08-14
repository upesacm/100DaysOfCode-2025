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

void buildMinHeap(int* heap, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

int extractMin(int* heap, int* size) {
    if (*size <= 0) return -1;
    
    int min = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    
    return min;
}

int kthSmallest(int* arr, int n, int k) {
    int* heap = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        heap[i] = arr[i];
    }
    
    buildMinHeap(heap, n);
    int heapSize = n;
    
    int result;
    for (int i = 0; i < k; i++) {
        result = extractMin(heap, &heapSize);
    }
    
    free(heap);
    return result;
}

int main() {
    int n, k;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    int result = kthSmallest(arr, n, k);
    printf("%d\n", result);
    
    free(arr);
    return 0;
}
