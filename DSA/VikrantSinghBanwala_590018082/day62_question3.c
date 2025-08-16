#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int *)malloc(capacity * sizeof(int));
    return minHeap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;
    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap *minHeap, int key) {
    if (minHeap->size < minHeap->capacity) {
        minHeap->array[minHeap->size] = key;
        minHeap->size++;
        for (int i = minHeap->size / 2 - 1; i >= 0; i--) {
            minHeapify(minHeap, i);
        }
    } else if (key > minHeap->array[0]) {
        minHeap->array[0] = key;
        minHeapify(minHeap, 0);
    }
}

int findKthLargestSum(int *arr, int n, int k) {
    MinHeap *minHeap = createMinHeap(k);
    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];
            insertMinHeap(minHeap, sum);
        }
    }

    int result = minHeap->array[0];
    free(minHeap->array);
    free(minHeap);
    return result;
}

int main() {
    int arr1[] = {10, -10, 20, -40};
    int k1 = 3;
    printf("%d\n", findKthLargestSum(arr1, sizeof(arr1) / sizeof(arr1[0]), k1));

    int arr2[] = {1, 2, 3};
    int k2 = 2;
    printf("%d\n", findKthLargestSum(arr2, sizeof(arr2) / sizeof(arr2[0]), k2));

    return 0;
}
