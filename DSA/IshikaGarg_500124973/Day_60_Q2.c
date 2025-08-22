#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapifyUpMax(int i) {
    int parent = (i - 1) / 2;
    if (i && maxHeap[i] > maxHeap[parent]) {
        swap(&maxHeap[i], &maxHeap[parent]);
        heapifyUpMax(parent);
    }
}
void heapifyDownMax(int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < maxSize && maxHeap[left] > maxHeap[largest]) largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest]) largest = right;
    if (largest != i) { swap(&maxHeap[i], &maxHeap[largest]); heapifyDownMax(largest); }
}
void insertMaxHeap(int val) { maxHeap[maxSize] = val; maxSize++; heapifyUpMax(maxSize - 1); }
int extractMax() { int root = maxHeap[0]; maxHeap[0] = maxHeap[--maxSize]; heapifyDownMax(0); return root; }

void heapifyUpMin(int i) {
    int parent = (i - 1) / 2;
    if (i && minHeap[i] < minHeap[parent]) {
        swap(&minHeap[i], &minHeap[parent]);
        heapifyUpMin(parent);
    }
}
void heapifyDownMin(int i) {
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if (left < minSize && minHeap[left] < minHeap[smallest]) smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest]) smallest = right;
    if (smallest != i) { swap(&minHeap[i], &minHeap[smallest]); heapifyDownMin(smallest); }
}
void insertMinHeap(int val) { minHeap[minSize] = val; minSize++; heapifyUpMin(minSize - 1); }
int extractMin() { int root = minHeap[0]; minHeap[0] = minHeap[--minSize]; heapifyDownMin(0); return root; }

void addNumber(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) insertMaxHeap(num);
    else insertMinHeap(num);

    // Balance heaps
    if (maxSize > minSize + 1) insertMinHeap(extractMax());
    else if (minSize > maxSize) insertMaxHeap(extractMin());
}

double getMedian() {
    if (maxSize == minSize) return (maxHeap[0] + minHeap[0]) / 2.0;
    else return maxHeap[0];
}

int main() {
    int arr[] = {5, 15, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        addNumber(arr[i]);
        printf("Median after %d: %.1f\n", arr[i], getMedian());
    }
    return 0;
}

