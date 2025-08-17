#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int distance;
    int value;
} Pair;

void swapPair(Pair *a, Pair *b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void heapifyDownPair(Pair heap[], int n, int i) {
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;
    
    if (left < n && heap[left].distance > heap[largest].distance)
        largest = left;
    if (right < n && heap[right].distance > heap[largest].distance)
        largest = right;
    if (largest != i) {
        swapPair(&heap[i], &heap[largest]);
        heapifyDownPair(heap, n, largest);
    }
}

void heapifyUpPair(Pair heap[], int i) {
    int parent = (i-1)/2;
    if (i > 0 && heap[i].distance > heap[parent].distance) {
        swapPair(&heap[i], &heap[parent]);
        heapifyUpPair(heap, parent);
    }
}

void insertMaxHeap(Pair heap[], int *n, Pair val) {
    heap[*n] = val;
    (*n)++;
    heapifyUpPair(heap, *n - 1);
}

Pair extractMax(Pair heap[], int *n) {
    Pair root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDownPair(heap, *n, 0);
    return root;
}

void kClosestNumbers(int arr[], int size, int target, int k) {
    Pair heap[100];
    int n = 0;
    
    for (int i = 0; i < size; i++) {
        int dist = abs(arr[i] - target);
        Pair p = {dist, arr[i]};
        insertMaxHeap(heap, &n, p);
        if (n > k) {
            extractMax(heap, &n); 
        }
    }
    
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i].value);
    }
    printf("]\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    kClosestNumbers(arr1, 5, 3, 2); // [2, 4]
    
    int arr2[] = {5, 6, 7, 8, 9};
    kClosestNumbers(arr2, 5, 7, 3); // [6, 7, 8]
    return 0;
}
