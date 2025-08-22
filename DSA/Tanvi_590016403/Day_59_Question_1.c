#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

// ========================== MIN HEAP ==========================
int minHeap[MAX];
int minHeapSize = 0;

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

void minHeapBubbleUp(int index) {
    while (index > 0 && minHeap[(index - 1) / 2] > minHeap[index]) {
        swap(&minHeap[(index - 1) / 2], &minHeap[index]);
        index = (index - 1) / 2;
    }
}

void minHeapInsert(int value) {
    minHeap[minHeapSize] = value;
    minHeapBubbleUp(minHeapSize);
    minHeapSize++;
}

void minHeapBubbleDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeapSize && minHeap[left] < minHeap[smallest])
        smallest = left;
    if (right < minHeapSize && minHeap[right] < minHeap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&minHeap[index], &minHeap[smallest]);
        minHeapBubbleDown(smallest);
    }
}

int extractMin() {
    if (minHeapSize <= 0)
        return INT_MIN;
    int root = minHeap[0];
    minHeap[0] = minHeap[minHeapSize - 1];
    minHeapSize--;
    minHeapBubbleDown(0);
    return root;
}

// ========================== MAX HEAP ==========================
int maxHeap[MAX];
int maxHeapSize = 0;

void maxHeapBubbleUp(int index) {
    while (index > 0 && maxHeap[(index - 1) / 2] < maxHeap[index]) {
        swap(&maxHeap[(index - 1) / 2], &maxHeap[index]);
        index = (index - 1) / 2;
    }
}

void maxHeapInsert(int value) {
    maxHeap[maxHeapSize] = value;
    maxHeapBubbleUp(maxHeapSize);
    maxHeapSize++;
}

void maxHeapBubbleDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < maxHeapSize && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < maxHeapSize && maxHeap[right] > maxHeap[largest])
        largest = right;

    if (largest != index) {
        swap(&maxHeap[index], &maxHeap[largest]);
        maxHeapBubbleDown(largest);
    }
}

int extractMax() {
    if (maxHeapSize <= 0)
        return INT_MIN;
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[maxHeapSize - 1];
    maxHeapSize--;
    maxHeapBubbleDown(0);
    return root;
}

// ========================== CHECK HEAPS EQUALITY ==========================
bool areHeapsIdentical(int arr1[], int size1, int arr2[], int size2) {
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

// ========================== MAIN ==========================
int main() {
    // --------- MIN HEAP DEMO ---------
    minHeapInsert(3);
    minHeapInsert(2);
    minHeapInsert(15);
    printf("ExtractMin from MinHeap: %d\n", extractMin()); // Output: 2

    // --------- MAX HEAP DEMO ---------
    maxHeapInsert(5);
    maxHeapInsert(1);
    maxHeapInsert(10);
    printf("ExtractMax from MaxHeap: %d\n", extractMax()); // Output: 10

    // --------- HEAP COMPARISON DEMO ---------
    int heap1[] = {10, 9, 8};
    int heap2[] = {10, 9, 8};
    if (areHeapsIdentical(heap1, 3, heap2, 3))
        printf("Heaps are identical\n");
    else
        printf("Heaps are not identical\n");

    return 0;
}
