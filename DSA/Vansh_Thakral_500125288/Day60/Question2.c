#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int leftHeap[MAX], rightHeap[MAX];
int leftSize = 0, rightSize = 0;

void swapInt(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}


void maxHeapifyUp(int heap[], int idx) {
    if (idx && heap[(idx-1)/2] < heap[idx]) {
        swapInt(&heap[idx], &heap[(idx-1)/2]);
        maxHeapifyUp(heap, (idx-1)/2);
    }
}
void maxHeapifyDown(int heap[], int size, int idx) {
    int largest = idx;
    int left = 2*idx + 1, right = 2*idx + 2;
    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;
    if (largest != idx) {
        swapInt(&heap[idx], &heap[largest]);
        maxHeapifyDown(heap, size, largest);
    }
}

// Min-heap for right
void minHeapifyUp(int heap[], int idx) {
    if (idx && heap[(idx-1)/2] > heap[idx]) {
        swapInt(&heap[idx], &heap[(idx-1)/2]);
        minHeapifyUp(heap, (idx-1)/2);
    }
}
void minHeapifyDown(int heap[], int size, int idx) {
    int smallest = idx;
    int left = 2*idx + 1, right = 2*idx + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != idx) {
        swapInt(&heap[idx], &heap[smallest]);
        minHeapifyDown(heap, size, smallest);
    }
}


void pushMax(int val) {
    leftHeap[leftSize] = val;
    maxHeapifyUp(leftHeap, leftSize++);
}
int popMax() {
    int root = leftHeap[0];
    leftHeap[0] = leftHeap[--leftSize];
    maxHeapifyDown(leftHeap, leftSize, 0);
    return root;
}


void pushMin(int val) {
    rightHeap[rightSize] = val;
    minHeapifyUp(rightHeap, rightSize++);
}
int popMin() {
    int root = rightHeap[0];
    rightHeap[0] = rightHeap[--rightSize];
    minHeapifyDown(rightHeap, rightSize, 0);
    return root;
}

void addNumber(int num) {
    pushMax(num);
    if (leftSize && rightSize && leftHeap[0] > rightHeap[0]) {
        pushMin(popMax());
    }
    if (leftSize > rightSize + 1) {
        pushMin(popMax());
    }
    if (rightSize > leftSize) {
        pushMax(popMin());
    }
}

double findMedian() {
    if (leftSize > rightSize) return leftHeap[0];
    return (leftHeap[0] + rightHeap[0]) / 2.0;
}


int main() {
    int nums[] = {5, 15, 1, 3};
    int n = sizeof(nums)/sizeof(nums[0]);
    for (int i = 0; i < n; i++) {
        addNumber(nums[i]);
        printf("%.1f ", findMedian());
    }
    printf("\n");
    return 0;
}
