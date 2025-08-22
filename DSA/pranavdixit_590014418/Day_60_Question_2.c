#include <stdio.h>

#define MAX 100

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void maxHeapifyUp(int idx) {
    while (idx > 0 && maxHeap[(idx - 1) / 2] < maxHeap[idx]) {
        swap(&maxHeap[(idx - 1) / 2], &maxHeap[idx]);
        idx = (idx - 1) / 2;
    }
}

void minHeapifyUp(int idx) {
    while (idx > 0 && minHeap[(idx - 1) / 2] > minHeap[idx]) {
        swap(&minHeap[(idx - 1) / 2], &minHeap[idx]);
        idx = (idx - 1) / 2;
    }
}

void maxHeapifyDown(int idx) {
    int largest = idx, l = 2 * idx + 1, r = 2 * idx + 2;
    if (l < maxSize && maxHeap[l] > maxHeap[largest]) largest = l;
    if (r < maxSize && maxHeap[r] > maxHeap[largest]) largest = r;
    if (largest != idx) { swap(&maxHeap[idx], &maxHeap[largest]); maxHeapifyDown(largest); }
}

void minHeapifyDown(int idx) {
    int smallest = idx, l = 2 * idx + 1, r = 2 * idx + 2;
    if (l < minSize && minHeap[l] < minHeap[smallest]) smallest = l;
    if (r < minSize && minHeap[r] < minHeap[smallest]) smallest = r;
    if (smallest != idx) { swap(&minHeap[idx], &minHeap[smallest]); minHeapifyDown(smallest); }
}

void addNumber(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) {
        maxHeap[maxSize++] = num;
        maxHeapifyUp(maxSize - 1);
    } else {
        minHeap[minSize++] = num;
        minHeapifyUp(minSize - 1);
    }

    if (maxSize > minSize + 1) {
        minHeap[minSize++] = maxHeap[0];
        minHeapifyUp(minSize - 1);
        maxHeap[0] = maxHeap[--maxSize];
        maxHeapifyDown(0);
    } else if (minSize > maxSize) {
        maxHeap[maxSize++] = minHeap[0];
        maxHeapifyUp(maxSize - 1);
        minHeap[0] = minHeap[--minSize];
        minHeapifyDown(0);
    }
}

double findMedian() {
    if (maxSize == minSize)
        return (maxHeap[0] + minHeap[0]) / 2.0;
    return maxHeap[0];
}

int main() {
    int arr[] = {5, 15, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        addNumber(arr[i]);
        printf("%.1f ", findMedian()); // Output: 5.0 10.0 5.0 4.0
    }
    printf("\n");
    return 0;
}
