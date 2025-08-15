#include <stdio.h>

#define MAX 100

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < maxSize && maxHeap[l] > maxHeap[largest]) largest = l;
    if (r < maxSize && maxHeap[r] > maxHeap[largest]) largest = r;
    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapifyDown(int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < minSize && minHeap[l] < minHeap[smallest]) smallest = l;
    if (r < minSize && minHeap[r] < minHeap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}

void insertMaxHeap(int val) {
    maxHeap[maxSize] = val;
    maxSize++;
    maxHeapifyUp(maxSize - 1);
}

void insertMinHeap(int val) {
    minHeap[minSize] = val;
    minSize++;
    minHeapifyUp(minSize - 1);
}

int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
    return root;
}

int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
    return root;
}

void addNumber(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) insertMaxHeap(num);
    else insertMinHeap(num);

    if (maxSize > minSize + 1) insertMinHeap(extractMax());
    else if (minSize > maxSize + 1) insertMaxHeap(extractMin());
}

double getMedian() {
    if (maxSize == minSize) return (maxHeap[0] + minHeap[0]) / 2.0;
    else if (maxSize > minSize) return maxHeap[0];
    else return minHeap[0];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        addNumber(num);
        printf("%.1f\n", getMedian());
    }
    return 0;
}
