#include <stdio.h>
#include <stdlib.h>

void heapify(int *heap, int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        int tmp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = tmp;
        heapify(heap, n, smallest);
    }
}

void buildHeap(int *heap, int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(heap, n, i);
}

int extractMin(int *heap, int *n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return min;
}

void insertHeap(int *heap, int *n, int val) {
    int i = (*n)++;
    heap[i] = val;
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        int tmp = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *heap = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &heap[i]);

    buildHeap(heap, n);

    int cost = 0;
    while (n > 1) {
        int a = extractMin(heap, &n);
        int b = extractMin(heap, &n);
        int sum = a + b;
        cost += sum;
        insertHeap(heap, &n, sum);
    }

    printf("%d\n", cost);
    free(heap);
    return 0;
}
