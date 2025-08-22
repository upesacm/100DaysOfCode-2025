#include <stdio.h>

#define MAX 99

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void bubbleDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        bubbleDown(smallest);
    }
}

void insert(int val) {
    heap[size] = val;
    bubbleUp(size);
    size++;
}

int extractMin() {
    if (size == 0)
        return -1;
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    bubbleDown(0);
    return min;
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
        printf("%d\n", extractMin());
    }
    return 0;
}
