#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int heap[], int i, int heapSize) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, smallest, heapSize);
    }
}


void buildMinHeap(int heap[], int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, i, heapSize);
    }
}

void replaceRootIfLarger(int heap[], int val, int heapSize) {
    if (val > heap[0]) {
        heap[0] = val;
        heapify(heap, 0, heapSize);
    }
}


void kLargestElements(int arr[], int n, int k) {
    if (k > n) {
        printf("k cannot be larger than array size.\n");
        return;
    }

    int heap[k];
    for (int i = 0; i < k; i++) {
        heap[i] = arr[i];
    }

    buildMinHeap(heap, k);

    for (int i = k; i < n; i++) {
        replaceRootIfLarger(heap, arr[i], k);
    }

    
    printf("K largest elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int k1 = 3;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    kLargestElements(arr1, n1, k1);  

    
    int arr2[] = {10, 15, 5};
    int k2 = 2;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    kLargestElements(arr2, n2, k2);  

    return 0;
}
