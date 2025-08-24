#include <stdio.h>

// ---------- Utility ----------
static inline void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// ---------- Heapify Up (used in insertion) ----------
void heapifyUp(int heap[], int index) {
    while (index > 1 && heap[index] > heap[index/2]) {
        int parent = index / 2;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

// ---------- Insert ----------
void insert(int heap[], int *size, int value) {
    (*size)++;
    heap[*size] = value;        // add element at the end
    heapifyUp(heap, *size);     // fix heap upwards
}

int main(void) {
    int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed heap
    int size = 5;

    printf("Initial heap:\n");
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]);
    printf("\n");

    // Test insertion
    insert(heap, &size, 60);
    printf("\nAfter inserting 60:\n");
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]);
    printf("\n");

    return 0;
}
