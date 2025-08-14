#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// ======================= HEAP STRUCTURE =======================
typedef struct {
    int *arr;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// -------- Min Heap Bubble Up & Down --------
void minHeapBubbleUp(Heap* heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2] > heap->arr[idx]) {
        swap(&heap->arr[(idx - 1) / 2], &heap->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

void minHeapBubbleDown(Heap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        minHeapBubbleDown(heap, smallest);
    }
}

void minHeapInsert(Heap* heap, int val) {
    heap->arr[heap->size] = val;
    minHeapBubbleUp(heap, heap->size);
    heap->size++;
}

int extractMin(Heap* heap) {
    if (heap->size == 0) return INT_MIN;
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapBubbleDown(heap, 0);
    return root;
}

// -------- Max Heap Bubble Up & Down --------
void maxHeapBubbleUp(Heap* heap, int idx) {
    while (idx > 0 && heap->arr[(idx - 1) / 2] < heap->arr[idx]) {
        swap(&heap->arr[(idx - 1) / 2], &heap->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

void maxHeapBubbleDown(Heap* heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;
    if (largest != idx) {
        swap(&heap->arr[idx], &heap->arr[largest]);
        maxHeapBubbleDown(heap, largest);
    }
}

void maxHeapInsert(Heap* heap, int val) {
    heap->arr[heap->size] = val;
    maxHeapBubbleUp(heap, heap->size);
    heap->size++;
}

int extractMax(Heap* heap) {
    if (heap->size == 0) return INT_MIN;
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapBubbleDown(heap, 0);
    return root;
}

// ==================== 1. SORT K-SORTED ARRAY ====================
void sortKSortedArray(int arr[], int n, int k) {
    Heap* heap = createHeap(k + 1);

    int idx = 0;
    for (int i = 0; i <= k && i < n; i++)
        minHeapInsert(heap, arr[i]);

    for (int i = k + 1; i < n; i++) {
        arr[idx++] = extractMin(heap);
        minHeapInsert(heap, arr[i]);
    }
    while (heap->size > 0) {
        arr[idx++] = extractMin(heap);
    }
    free(heap->arr);
    free(heap);
}

// ==================== 2. MEDIAN IN A STREAM ====================
void addNumber(int num, Heap* low, Heap* high) {
    if (low->size == 0 || num <= low->arr[0])
        maxHeapInsert(low, num);
    else
        minHeapInsert(high, num);

    if (low->size > high->size + 1)
        minHeapInsert(high, extractMax(low));
    else if (high->size > low->size)
        maxHeapInsert(low, extractMin(high));
}

double getMedian(Heap* low, Heap* high) {
    if (low->size == high->size)
        return (low->arr[0] + high->arr[0]) / 2.0;
    return low->arr[0];
}

// ==================== 3. TOP K FREQUENT ELEMENTS ====================
typedef struct {
    int value;
    int freq;
} FreqItem;

void minHeapBubbleUpFreq(FreqItem heap[], int idx) {
    while (idx > 0 && heap[(idx - 1) / 2].freq > heap[idx].freq) {
        FreqItem temp = heap[(idx - 1) / 2];
        heap[(idx - 1) / 2] = heap[idx];
        heap[idx] = temp;
        idx = (idx - 1) / 2;
    }
}

void minHeapBubbleDownFreq(FreqItem heap[], int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;
    if (smallest != idx) {
        FreqItem temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        minHeapBubbleDownFreq(heap, size, smallest);
    }
}

void topKFrequent(int arr[], int n, int k) {
    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++)
        freqMap[arr[i] + 500]++;

    FreqItem heap[k];
    int heapSize = 0;

    for (int i = 0; i < 1000; i++) {
        if (freqMap[i] > 0) {
            if (heapSize < k) {
                heap[heapSize].value = i - 500;
                heap[heapSize].freq = freqMap[i];
                minHeapBubbleUpFreq(heap, heapSize);
                heapSize++;
            } else if (freqMap[i] > heap[0].freq) {
                heap[0].value = i - 500;
                heap[0].freq = freqMap[i];
                minHeapBubbleDownFreq(heap, heapSize, 0);
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i].value);
    printf("\n");
}

// ========================== MAIN ==========================
int main() {
    // --- 1. Sort K-Sorted Array ---
    int arr1[] = {6, 5, 3, 2, 8, 10, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sortKSortedArray(arr1, n1, 3);
    printf("Sorted K-Sorted Array: ");
    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    // --- 2. Median in a Stream ---
    int stream[] = {5, 15, 1, 3};
    int ns = sizeof(stream) / sizeof(stream[0]);
    Heap* low = createHeap(100); // max heap
    Heap* high = createHeap(100); // min heap
    for (int i = 0; i < ns; i++) {
        addNumber(stream[i], low, high);
        printf("Median after inserting %d: %.1f\n", stream[i], getMedian(low, high));
    }
    free(low->arr); free(high->arr); free(low); free(high);

    // --- 3. Top K Frequent Elements ---
    int arr2[] = {1, 1, 1, 2, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    topKFrequent(arr2, n2, 2);

    return 0;
}
