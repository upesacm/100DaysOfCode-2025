#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Element;

void swapElem(Element *a, Element *b) {
    Element t = *a; *a = *b; *b = t;
}

void heapifyDownElem(Element heap[], int size, int i) {
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if (left < size && heap[left].freq < heap[smallest].freq) smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq) smallest = right;
    if (smallest != i) {
        swapElem(&heap[i], &heap[smallest]);
        heapifyDownElem(heap, size, smallest);
    }
}

void heapifyUpElem(Element heap[], int i) {
    if (i && heap[(i-1)/2].freq > heap[i].freq) {
        swapElem(&heap[i], &heap[(i-1)/2]);
        heapifyUpElem(heap, (i-1)/2);
    }
}

void pushElem(Element heap[], int *size, Element e) {
    heap[*size] = e;
    (*size)++;
    heapifyUpElem(heap, *size - 1);
}

Element popElem(Element heap[], int *size) {
    Element root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDownElem(heap, *size, 0);
    return root;
}

void topKFrequent(int arr[], int n, int k) {

    int freqMap[1000] = {0};
    for (int i = 0; i < n; i++) freqMap[arr[i] + 500]++;

    Element heap[k];
    int size = 0;

    for (int num = -500; num <= 500; num++) {
        if (freqMap[num+500] > 0) {
            Element e = {num, freqMap[num+500]};
            pushElem(heap, &size, e);
            if (size > k) popElem(heap, &size);
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i].val);
    }
    printf("\n");
}


int main() {
    int arr[] = {1, 1, 1, 2, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    topKFrequent(arr, n, 2);
    return 0;
}
