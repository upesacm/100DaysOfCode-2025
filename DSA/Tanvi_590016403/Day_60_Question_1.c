#include <stdio.h>
#include <stdlib.h>

// ---------------- Heap Utilities ----------------
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void minHeapify(int heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) { swap(&heap[i], &heap[smallest]); minHeapify(heap, n, smallest); }
}

void maxHeapify(int heap[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;
    if (largest != i) { swap(&heap[i], &heap[largest]); maxHeapify(heap, n, largest); }
}

void buildMinHeap(int heap[], int n) {
    for (int i = n/2-1; i >= 0; i--) minHeapify(heap, n, i);
}

void buildMaxHeap(int heap[], int n) {
    for (int i = n/2-1; i >= 0; i--) maxHeapify(heap, n, i);
}

// ---------------- 1. Sort K-Sorted Array ----------------
void sortKSortedArray(int arr[], int n, int k) {
    int size = (k+1 < n) ? k+1 : n;
    int heap[size];
    for (int i = 0; i < size; i++) heap[i] = arr[i];
    buildMinHeap(heap, size);

    int idx = 0;
    for (int i = size; i < n; i++) {
        arr[idx++] = heap[0];
        heap[0] = arr[i];
        minHeapify(heap, size, 0);
    }
    while (size > 0) {
        arr[idx++] = heap[0];
        heap[0] = heap[size-1];
        size--;
        minHeapify(heap, size, 0);
    }
}

// ---------------- 2. Median in a Stream ----------------
#define MAX 1000
int maxHeap[MAX], minHeap[MAX];
int maxSize = 0, minSize = 0;

void insertMaxHeap(int val) {
    maxHeap[maxSize++] = val;
    int i = maxSize-1;
    while (i != 0 && maxHeap[(i-1)/2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insertMinHeap(int val) {
    minHeap[minSize++] = val;
    int i = minSize-1;
    while (i != 0 && minHeap[(i-1)/2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapify(maxHeap, maxSize, 0);
    return root;
}

int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapify(minHeap, minSize, 0);
    return root;
}

void medianInStream(int arr[], int n) {
    maxSize = minSize = 0;
    for (int i = 0; i < n; i++) {
        if (maxSize == 0 || arr[i] <= maxHeap[0])
            insertMaxHeap(arr[i]);
        else
            insertMinHeap(arr[i]);

        if (maxSize > minSize + 1)
            insertMinHeap(extractMax());
        else if (minSize > maxSize)
            insertMaxHeap(extractMin());

        if (maxSize == minSize)
            printf("%.1f ", (maxHeap[0] + minHeap[0]) / 2.0);
        else
            printf("%d ", maxHeap[0]);
    }
    printf("\n");
}

// ---------------- 3. Top K Frequent Elements ----------------
typedef struct { int val; int freq; } Element;

void freqHeapify(Element heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l].freq < heap[smallest].freq) smallest = l;
    if (r < n && heap[r].freq < heap[smallest].freq) smallest = r;
    if (smallest != i) {
        Element t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        freqHeapify(heap, n, smallest);
    }
}

void topKFrequent(int arr[], int n, int k) {
    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++) freqMap[arr[i]+500]++;

    Element heap[k];
    int size = 0;
    for (int i = 0; i < 1000; i++) {
        if (freqMap[i] > 0) {
            Element e = {i-500, freqMap[i]};
            if (size < k) {
                heap[size++] = e;
                if (size == k) {
                    for (int j = k/2-1; j >= 0; j--)
                        freqHeapify(heap, k, j);
                }
            } else if (e.freq > heap[0].freq) {
                heap[0] = e;
                freqHeapify(heap, k, 0);
            }
        }
    }
    printf("Top %d frequent: ", k);
    for (int i = 0; i < size; i++) printf("%d ", heap[i].val);
    printf("\n");
}

// ---------------- Main Menu ----------------
int main() {
    int choice;
    do {
        printf("\n--- Heap Based Problems Menu ---\n");
        printf("1. Sort K-Sorted Array\n");
        printf("2. Median in a Stream\n");
        printf("3. Top K Frequent Elements\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int arr[] = {6,5,3,2,8,10,9};
            int n = sizeof(arr)/sizeof(arr[0]);
            sortKSortedArray(arr, n, 3);
            printf("Sorted: ");
            for (int i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        else if (choice == 2) {
            int arr[] = {5,15,1,3};
            int n = sizeof(arr)/sizeof(arr[0]);
            printf("Median sequence: ");
            medianInStream(arr, n);
        }
        else if (choice == 3) {
            int arr[] = {1,1,1,2,2,3};
            int n = sizeof(arr)/sizeof(arr[0]);
            topKFrequent(arr, n, 2);
        }
    } while (choice != 0);

    return 0;
}
