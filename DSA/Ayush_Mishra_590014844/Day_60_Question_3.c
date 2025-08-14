#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Element;

void swap(Element *a, Element *b) {
    Element t = *a;
    *a = *b;
    *b = t;
}

void heapify(Element heap[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && heap[l].freq < heap[smallest].freq)
        smallest = l;
    if (r < n && heap[r].freq < heap[smallest].freq)
        smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(Element heap[], int *size, Element e) {
    heap[*size] = e;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1)/2].freq > heap[i].freq) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter value of k: ");
    scanf("%d", &k);

    int freqMap[10000] = {0};
    for (int i = 0; i < n; i++)
        freqMap[arr[i] + 5000]++;

    Element heap[k];
    int size = 0;
    for (int i = 0; i < 10000; i++) {
        if (freqMap[i] > 0) {
            Element e;
            e.val = i - 5000;
            e.freq = freqMap[i];
            if (size < k)
                insertHeap(heap, &size, e);
            else if (e.freq > heap[0].freq) {
                heap[0] = e;
                heapify(heap, size, 0);
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i].val);
    return 0;
}
