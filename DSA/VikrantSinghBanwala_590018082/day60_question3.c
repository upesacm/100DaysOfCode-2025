#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    int frequency;
} Element;

typedef struct {
    Element *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->data = (Element *)malloc(capacity * sizeof(Element));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left].frequency < heap->data[smallest].frequency) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right].frequency < heap->data[smallest].frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMinHeap(MinHeap *heap, Element element) {
    if (heap->size < heap->capacity) {
        heap->data[heap->size++] = element;
        for (int i = (heap->size / 2) - 1; i >= 0; i--) {
            minHeapify(heap, i);
        }
    } else if (element.frequency > heap->data[0].frequency) {
        heap->data[0] = element;
        minHeapify(heap, 0);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int frequencyMap[20001] = {0}; // Assuming nums are in the range [-10000, 10000]
    for (int i = 0; i < numsSize; i++) {
        frequencyMap[nums[i] + 10000]++;
    }

    MinHeap *minHeap = createMinHeap(k);
    for (int i = 0; i < 20001; i++) {
        if (frequencyMap[i] > 0) {
            Element element = {i - 10000, frequencyMap[i]};
            insertMinHeap(minHeap, element);
        }
    }

    int *result = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = minHeap->data[i].value;
    }

    *returnSize = k;
    free(minHeap->data);
    free(minHeap);
    return result;
}

int main() {
    int arr1[] = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    int returnSize1;
    int *result1 = topKFrequent(arr1, sizeof(arr1) / sizeof(arr1[0]), k1, &returnSize1);
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    int arr2[] = {4, 1, -1, 2, -1, 2, 3};
    int k2 = 2;
    int returnSize2;
    int *result2 = topKFrequent(arr2, sizeof(arr2) / sizeof(arr2[0]), k2, &returnSize2);
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    return 0;
}
