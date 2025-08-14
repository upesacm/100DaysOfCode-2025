#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
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
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;
        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&h->arr[index], &h->arr[smallest]);
            index = smallest;
        } else break;
    }
}

void insert(MinHeap *h, int value) {
    h->arr[h->size] = value;
    h->size++;
    bubbleUp(h, h->size - 1);
}

int extractMin(MinHeap *h) {
    if (h->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    bubbleDown(h, 0);
    return min;
}

int main() {
    MinHeap h = {.size = 0};

    insert(&h, 3);
    insert(&h, 2);
    insert(&h, 15);
    printf("%d\n", extractMin(&h)); 

    MinHeap h2 = {.size = 0};
    insert(&h2, 10);
    insert(&h2, 5);
    insert(&h2, 20);
    insert(&h2, 8);
    printf("%d, %d\n", extractMin(&h2), extractMin(&h2)); 

    return 0;
}

