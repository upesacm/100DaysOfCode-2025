#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} MaxHeap;

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp2(MaxHeap *h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->arr[parent] < h->arr[index]) {
            swap2(&h->arr[parent], &h->arr[index]);
            index = parent;
        } else break;
    }
}

void bubbleDown2(MaxHeap *h, int index) {
    int left, right, largest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;

        if (left < h->size && h->arr[left] > h->arr[largest])
            largest = left;
        if (right < h->size && h->arr[right] > h->arr[largest])
            largest = right;

        if (largest != index) {
            swap2(&h->arr[index], &h->arr[largest]);
            index = largest;
        } else break;
    }
}

void insertMax(MaxHeap *h, int value) {
    h->arr[h->size] = value;
    h->size++;
    bubbleUp2(h, h->size - 1);
}

int extractMax(MaxHeap *h) {
    if (h->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int max = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    bubbleDown2(h, 0);
    return max;
}

int main() {
    MaxHeap h = {.size = 0};

    insertMax(&h, 5);
    insertMax(&h, 1);
    insertMax(&h, 10);
    printf("%d\n", extractMax(&h)); 

    MaxHeap h2 = {.size = 0};
    insertMax(&h2, 3);
    insertMax(&h2, 7);
    insertMax(&h2, 2);
    insertMax(&h2, 9);
    printf("%d, %d\n", extractMax(&h2), extractMax(&h2)); 

    return 0;
}

