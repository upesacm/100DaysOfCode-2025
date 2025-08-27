#include <stdio.h>
#include <stdlib.h>

void minHeapify(int heap[], int i, int size) {
    int smallest = i, left = 2*i + 1, right = 2*i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, smallest, size);
    }
}

int extractMin(int heap[], int *size) {
    int min = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, 0, *size);
    return min;
}

void insertHeap(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int heap[n], size = n;
    for (int i = 0; i < n; i++) scanf("%d", &heap[i]);

    for (int i = n/2 - 1; i >= 0; i--) minHeapify(heap, i, size);

    int cost = 0;
    while (size > 1) {
        int first = extractMin(heap, &size);
        int second = extractMin(heap, &size);
        int sum = first + second;
        cost += sum;
        insertHeap(heap, &size, sum);
    }

    printf("%d\n", cost);
    return 0;
}
