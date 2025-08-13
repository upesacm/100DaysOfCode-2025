#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(MinHeap *h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->arr[parent] > h->arr[index]) {
            swap(&h->arr[parent], &h->arr[index]);
            index = parent;
        } else break;
    }
}

void bubbleDown(MinHeap *h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->arr[index], &h->arr[smallest]);
        bubbleDown(h, smallest);
    }
}

void insert(MinHeap *h, int value) {
    if (h->size == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    h->arr[h->size] = value;
    h->size++;
    bubbleUp(h, h->size - 1);
}

int extractMin(MinHeap *h) {
    if (h->size <= 0) return -1;
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    bubbleDown(h, 0);
    return root;
}

int main() {
    MinHeap heap;
    heap.size = 0;

    insert(&heap, 3);
    insert(&heap, 2);
    insert(&heap, 15);
    printf("%d\n", extractMin(&heap)); // Output: 2

    insert(&heap, 10);
    insert(&heap, 5);
    insert(&heap, 20);
    insert(&heap, 8);
    printf("%d\n", extractMin(&heap)); // Output: 5
    printf("%d\n", extractMin(&heap)); // Output: 8

    return 0;
}

