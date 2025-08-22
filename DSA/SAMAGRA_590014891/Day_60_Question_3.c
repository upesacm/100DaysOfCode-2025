#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, freq;
} Element;

void swap(Element *a, Element *b) {
    Element t = *a; *a = *b; *b = t;
}

void heapify(Element heap[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && heap[l].freq < heap[smallest].freq) smallest = l;
    if (r < n && heap[r].freq < heap[smallest].freq) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);

    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++) freqMap[arr[i] + 500]++;

    Element heap[k];
    int heapSize = 0;

    for (int i = 0; i < 1000; i++) {
        if (freqMap[i] > 0) {
            Element e = {i - 500, freqMap[i]};
            if (heapSize < k) {
                heap[heapSize++] = e;
                if (heapSize == k) {
                    for (int j = k / 2 - 1; j >= 0; j--) heapify(heap, heapSize, j);
                }
            } else if (e.freq > heap[0].freq) {
                heap[0] = e;
                heapify(heap, heapSize, 0);
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < heapSize; i++) printf("%d ", heap[i].val);
    return 0;
}
