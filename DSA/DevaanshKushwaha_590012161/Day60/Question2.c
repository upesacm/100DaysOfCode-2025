#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Max-Heap (for left half)
int maxHeap[MAX], maxSize = 0;

// Min-Heap (for right half)
int minHeap[MAX], minSize = 0;

// Swap utility
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ---------- Max-Heap functions ----------
void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < maxSize && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest])
        largest = right;

    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void insertMaxHeap(int val) {
    maxHeap[maxSize] = val;
    maxSize++;
    maxHeapifyUp(maxSize - 1);
}

int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
    return root;
}

int getMax() {
    return maxHeap[0];
}

// ---------- Min-Heap functions ----------
void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < minSize && minHeap[left] < minHeap[smallest])
        smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}

void insertMinHeap(int val) {
    minHeap[minSize] = val;
    minSize++;
    minHeapifyUp(minSize - 1);
}

int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
    return root;
}

int getMin() {
    return minHeap[0];
}

// ---------- Median Logic ----------
void addNumber(int num) {
    // Step 1: Insert into Max-Heap (left side)
    if (maxSize == 0 || num <= getMax())
        insertMaxHeap(num);
    else
        insertMinHeap(num);

    // Step 2: Balance heaps
    if (maxSize > minSize + 1) {
        insertMinHeap(extractMax());
    } else if (minSize > maxSize) {
        insertMaxHeap(extractMin());
    }
}

double getMedian() {
    if (maxSize == minSize)
        return (getMax() + getMin()) / 2.0;
    return getMax();
}

int main() {
    int n;
    printf("Enter number of elements in stream: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter stream elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Running medians: ");
    for (int i = 0; i < n; i++) {
        addNumber(arr[i]);
        printf("%.1f ", getMedian());
    }
    printf("\n");

    return 0;
}
