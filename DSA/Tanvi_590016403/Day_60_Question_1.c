#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ------------------- Heap Utility Functions -------------------
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Min-heap functions
void heapifyMin(int heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyMin(heap, n, smallest);
    }
}

void buildMinHeap(int heap[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapifyMin(heap, n, i);
}

// Max-heap functions
void heapifyMax(int heap[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyMax(heap, n, largest);
    }
}

void buildMaxHeap(int heap[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapifyMax(heap, n, i);
}

// ------------------- 1. Sort K-Sorted Array -------------------
void sortKSortedArray(int arr[], int n, int k) {
    int size = (k+1 < n) ? (k+1) : n;
    int heap[size];
    for (int i = 0; i < size; i++)
        heap[i] = arr[i];
    buildMinHeap(heap, size);

    int target = 0;
    for (int i = size; i < n; i++) {
        arr[target++] = heap[0];
        heap[0] = arr[i];
        heapifyMin(heap, size, 0);
    }
    while (size > 0) {
        arr[target++] = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapifyMin(heap, size, 0);
    }
}

// ------------------- 2. Median in a Stream -------------------
void insertMaxHeap(int heap[], int *size, int value) {
    heap[(*size)++] = value;
    int i = *size - 1;
    while (i != 0 && heap[(i-1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insertMinHeap(int heap[], int *size, int value) {
    heap[(*size)++] = value;
    int i = *size - 1;
    while (i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyMax(heap, *size, 0);
    return root;
}

int extractMin(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyMin(heap, *size, 0);
    return root;
}

void medianInStream(int arr[], int n) {
    int maxHeap[1000], minHeap[1000];
    int maxSize = 0, minSize = 0;

    for (int i = 0; i < n; i++) {
        if (maxSize == 0 || arr[i] <= maxHeap[0]) {
            insertMaxHeap(maxHeap, &maxSize, arr[i]);
        } else {
            insertMinHeap(minHeap, &minSize, arr[i]);
        }

        if (maxSize > minSize + 1) {
            insertMinHeap(minHeap, &minSize, extractMax(maxHeap, &maxSize));
        } else if (minSize > maxSize) {
            insertMaxHeap(maxHeap, &maxSize, extractMin(minHeap, &minSize));
        }

        if (maxSize == minSize)
            printf("%.1f ", (maxHeap[0] + minHeap[0]) / 2.0);
        else
            printf("%d ", maxHeap[0]);
    }
    printf("\n");
}

// ------------------- 3. Top K Frequent Elements -------------------
typedef struct {
    int value;
    int freq;
} Element;

void heapifyMinFreq(Element heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l].freq < heap[smallest].freq) smallest = l;
    if (r < n && heap[r].freq < heap[smallest].freq) smallest = r;
    if (smallest != i) {
        Element temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapifyMinFreq(heap, n, smallest);
    }
}

void topKFrequent(int arr[], int n, int k) {
    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++)
        freqMap[arr[i] + 500]++; // Offset for negatives

    Element heap[k];
    int size = 0;
    for (int i = 0; i < 1000; i++) {
        if (freqMap[i] > 0) {
            Element e = {i - 500, freqMap[i]};
            if (size < k) {
                heap[size++] = e;
                if (size == k) {
                    for (int j = k/2-1; j >= 0; j--)
                        heapifyMinFreq(heap, k, j);
                }
            } else if (e.freq > heap[0].freq) {
                heap[0] = e;
                heapifyMinFreq(heap, k, 0);
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i].value);
    printf("\n");
}

// ------------------- Main -------------------
int main() {
    int arr1[] = {6, 5, 3, 2, 8, 10, 9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    sortKSortedArray(arr1, n1, 3);
    printf("Sorted K-sorted array: ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    int stream[] = {5, 15, 1, 3};
    int n2 = sizeof(stream)/sizeof(stream[0]);
    printf("Median in stream: ");
    medianInStream(stream, n2);

    int arr2[] = {1, 1, 1, 2, 2, 3};
    int n3 = sizeof(arr2)/sizeof(arr2[0]);
    topKFrequent(arr2, n3, 2);

    return 0;
}
