#include <stdio.h>
#include <stdlib.h>

#define MAX 999

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int extractMin(int heap[], int *n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return min;
}

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    int i = *n;
    (*n)++;
    while (i != 0 && heap[(i - 1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

int main() {
    int n;
    int heap[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(heap, n, i);

    int cost = 0;
    while (n > 1) {
        int first = extractMin(heap, &n);
        int second = extractMin(heap, &n);
        cost += first + second;
        insertHeap(heap, &n, first + second);
    }

    printf("%d\n", cost);
    return 0;
}
