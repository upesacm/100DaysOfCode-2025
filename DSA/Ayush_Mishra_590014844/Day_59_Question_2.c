#include <stdio.h>
#include <stdlib.h>

#define MAX 99

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void bubbleDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        bubbleDown(largest);
    }
}

void insert(int val) {
    heap[size] = val;
    bubbleUp(size);
    size++;
}

int extractMax() {
    if (size == 0)
        return -1;
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    bubbleDown(0);
    return max;
}

int main() {
    int n, val, op;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }
    scanf("%d", &op);
    for (int i = 0; i < op; i++) {
        printf("%d\n", extractMax());
    }
    return 0;
}
