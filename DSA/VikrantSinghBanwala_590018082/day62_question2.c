#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int value;
    int distance;
} Element;

typedef struct {
    Element *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->array = (Element *)malloc(capacity * sizeof(Element));
    return maxHeap;
}

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap *maxHeap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < maxHeap->size && maxHeap->array[left].distance > maxHeap->array[largest].distance)
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right].distance > maxHeap->array[largest].distance)
        largest = right;

    if (largest != idx) {
        swap(&maxHeap->array[idx], &maxHeap->array[largest]);
        maxHeapify(maxHeap, largest);
    }
}

void insertMaxHeap(MaxHeap *maxHeap, Element elem) {
    if (maxHeap->size < maxHeap->capacity) {
        maxHeap->array[maxHeap->size] = elem;
        maxHeap->size++;
        for (int i = maxHeap->size / 2 - 1; i >= 0; i--) {
            maxHeapify(maxHeap, i);
        }
    } else if (elem.distance < maxHeap->array[0].distance) {
        maxHeap->array[0] = elem;
        maxHeapify(maxHeap, 0);
    }
}

int* kClosestNumbers(int *arr, int n, int target, int k) {
    MaxHeap *maxHeap = createMaxHeap(k);
    for (int i = 0; i < n; i++) {
        Element elem;
        elem.value = arr[i];
        elem.distance = abs(arr[i] - target);
        insertMaxHeap(maxHeap, elem);
    }

    int *result = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = maxHeap->array[i].value;
    }

    free(maxHeap->array);
    free(maxHeap);
    return result;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int target1 = 3, k1 = 2;
    int *result1 = kClosestNumbers(arr1, sizeof(arr1) / sizeof(arr1[0]), target1, k1);
    for (int i = 0; i < k1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    int arr2[] = {5, 6, 7, 8, 9};
    int target2 = 7, k2 = 3;
    int *result2 = kClosestNumbers(arr2, sizeof(arr2) / sizeof(arr2[0]), target2, k2);
    for (int i = 0; i < k2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    return 0;
}
