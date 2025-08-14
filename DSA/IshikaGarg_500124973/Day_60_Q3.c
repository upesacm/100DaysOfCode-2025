#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Element;

void swap(Element *a, Element *b) {
    Element t = *a; *a = *b; *b = t;
}

void heapifyDown(Element heap[], int size, int i) {
    int smallest = i;
    int left = 2*i+1, right = 2*i+2;
    if (left < size && heap[left].freq < heap[smallest].freq) smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(Element heap[], int i) {
    int parent = (i - 1) / 2;
    if (i && heap[i].freq < heap[parent].freq) {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

void insertHeap(Element heap[], int *size, Element val) {
    heap[(*size)++] = val;
    heapifyUp(heap, *size - 1);
}

Element extractMin(Element heap[], int *size) {
    Element root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

void topKFrequent(int arr[], int n, int k) {
    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++)
        freqMap[arr[i] + 500]++; // offset for negatives

    Element heap[k];
    int size = 0;

    for (int num = -500; num <= 500; num++) {
        if (freqMap[num + 500] > 0) {
            Element e = {num, freqMap[num + 500]};
            if (size < k) insertHeap(heap, &size, e);
            else if (e.freq > heap[0].freq) {
                extractMin(heap, &size);
                insertHeap(heap, &size, e);
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i].num);
    printf("\n");
}

int main() {
    int arr[] = {4, 1, -1, 2, -1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    topKFrequent(arr, n, k);
    return 0;
}

