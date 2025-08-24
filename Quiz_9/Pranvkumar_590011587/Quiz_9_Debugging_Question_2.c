#include <stdio.h>

// ---------- Utility ----------
static inline void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// ---------- Heapify Down (used in deletion) ----------
void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int largest = index;
        int left  = 2 * index;
        int right = 2 * index + 1;

        if (left  <= size && heap[left]  > heap[largest]) largest = left;
        if (right <= size && heap[right] > heap[largest]) largest = right;

        if (largest == index) break;
        swap(&heap[index], &heap[largest]);
        index = largest;
    }
}

// ---------- Delete Max ----------
int deleteMax(int heap[], int *size) {
    if (*size == 0) return -1;       // empty heap case
    int removed = heap[1];           // root is max
    heap[1] = heap[*size];           // move last to root
    (*size)--;                       // shrink heap
    heapifyDown(heap, *size, 1);     // fix heap downwards
    return removed;
}

int main(void) {
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed heap
    int size = 6;

    printf("Initial heap:\n");
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]);
    printf("\n");

    // Test deletion
    int max = deleteMax(heap, &size);
    printf("\nAfter deleting max (%d):\n", max);
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]);
    printf("\n");

    return 0;
}
