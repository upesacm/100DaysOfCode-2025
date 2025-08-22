#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1)/2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1)/2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void maxHeapifyDown(int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < maxSize && maxHeap[l] > maxHeap[largest])
        largest = l;
    if (r < maxSize && maxHeap[r] > maxHeap[largest])
        largest = r;
    if (largest != i) {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void minHeapifyDown(int i) {
    int smallest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < minSize && minHeap[l] < minHeap[smallest])
        smallest = l;
    if (r < minSize && minHeap[r] < minHeap[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
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

double getMedian() {
    if (maxSize == minSize)
        return (maxHeap[0] + minHeap[0]) / 2.0;
    else
        return maxHeap[0];
}

int main() {
    int n;
    printf("Enter number of elements in stream: ");
    scanf("%d", &n);
    int num;
    printf("Enter stream elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        addNumber(num);
        printf("Median after %d insertions: %.1f\n", i + 1, getMedian());
    }
    return 0;
}
