
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void maxHeapifyDown(int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < maxSize && maxHeap[left] > maxHeap[largest]) largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest]) largest = right;
    if (largest != i) { swap(&maxHeap[i], &maxHeap[largest]); maxHeapifyDown(largest); }
}

void minHeapifyDown(int i) {
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if (left < minSize && minHeap[left] < minHeap[smallest]) smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest]) smallest = right;
    if (smallest != i) { swap(&minHeap[i], &minHeap[smallest]); minHeapifyDown(smallest); }
}

void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i-1)/2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i-1)/2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insertMaxHeap(int value) {
    maxHeap[maxSize] = value;
    maxSize++;
    maxHeapifyUp(maxSize-1);
}

void insertMinHeap(int value) {
    minHeap[minSize] = value;
    minSize++;
    minHeapifyUp(minSize-1);
}

int extractMaxHeap() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[maxSize-1];
    maxSize--;
    maxHeapifyDown(0);
    return root;
}

int extractMinHeap() {
    int root = minHeap[0];
    minHeap[0] = minHeap[minSize-1];
    minSize--;
    minHeapifyDown(0);
    return root;
}

void balanceHeaps() {
    if (maxSize > minSize + 1) {
        insertMinHeap(extractMaxHeap());
    } else if (minSize > maxSize) {
        insertMaxHeap(extractMinHeap());
    }
}

void addNumber(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) {
        insertMaxHeap(num);
    } else {
        insertMinHeap(num);
    }
    balanceHeaps();
}

double getMedian() {
    if (maxSize == minSize) return (maxHeap[0] + minHeap[0]) / 2.0;
    return maxHeap[0];
}

int main() {
    int n, num;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        addNumber(num);
        printf("Median after inserting %d: %.1f\n", num, getMedian());
    }
    return 0;
}
