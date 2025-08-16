#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int dist;
} Element;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Element heap[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left].dist > heap[largest].dist)
        largest = left;
    if (right < n && heap[right].dist > heap[largest].dist)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void insertHeap(Element heap[], int *n, Element val) {
    heap[*n] = val;
    int i = *n;
    (*n)++;
    while (i != 0 && heap[(i - 1)/2].dist < heap[i].dist) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void extractMax(Element heap[], int *n) {
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
}

int main() {
    int arr[1000], n, k, target;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d %d", &target, &k);

    Element heap[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        Element e;
        e.val = arr[i];
        e.dist = abs(arr[i] - target);
        if (size < k)
            insertHeap(heap, &size, e);
        else if (e.dist < heap[0].dist) {
            extractMax(heap, &size);
            insertHeap(heap, &size, e);
        }
    }

    for (int i = 0; i < size; i++)
        printf("%d ", heap[i].val);
    printf("\n");
    return 0;
}
