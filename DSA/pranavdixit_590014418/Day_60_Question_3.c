#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

void swap(Pair *a, Pair *b) { Pair t = *a; *a = *b; *b = t; }

void heapify(Pair arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l].freq < arr[smallest].freq) smallest = l;
    if (r < n && arr[r].freq < arr[smallest].freq) smallest = r;
    if (smallest != i) { swap(&arr[i], &arr[smallest]); heapify(arr, n, smallest); }
}

void buildMinHeap(Pair arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void topKFrequent(int nums[], int n, int k) {
    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++) freqMap[nums[i] + 500]++;

    Pair heap[k];
    int heapSize = 0;
    for (int i = 0; i < 1000; i++) {
        if (freqMap[i] > 0) {
            if (heapSize < k) {
                heap[heapSize++] = (Pair){i - 500, freqMap[i]};
                if (heapSize == k) buildMinHeap(heap, heapSize);
            } else if (freqMap[i] > heap[0].freq) {
                heap[0] = (Pair){i - 500, freqMap[i]};
                heapify(heap, heapSize, 0);
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i].num);
    printf("\n");
}

int main() {
    int arr[] = {1, 1, 1, 2, 2, 3};
    topKFrequent(arr, 6, 2); // Output: 1 2
    return 0;
}
