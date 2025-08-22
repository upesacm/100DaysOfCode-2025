#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MaxHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(MaxHeap *h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->arr[parent] < h->arr[index]) {
            swap(&h->arr[parent], &h->arr[index]);
            index = parent;
        } else break;
    }
}

void bubbleDown(MaxHeap *h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] > h->arr[largest])
        largest = left;
    if (right < h->size && h->arr[right] > h->arr[largest])
        largest = right;

    if (largest != index) {
        swap(&h->arr[index], &h->arr[largest]);
        bubbleDown(h, largest);
    }
}

void insert(MaxHeap *h, int value) {
    if (h->size == MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    h->arr[h->size] = value;
    h->size++;
    bubbleUp(h, h->size - 1);
}

int extractMax(MaxHeap *h) {
    if (h->size <= 0) return -1;
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    bubbleDown(h, 0);
    return root;
}

int main() {
    MaxHeap heap;
    heap.size = 0;

    insert(&heap, 5);
    insert(&heap, 1);
    insert(&heap, 10);
    printf("%d\n", extractMax(&heap)); 

    insert(&heap, 3);
    insert(&heap, 7);
    insert(&heap, 2);
    insert(&heap, 9);
    printf("%d\n", extractMax(&heap)); 
    printf("%d\n", extractMax(&heap)); 
    return 0;
}

