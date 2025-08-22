#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax() {
    if (size <= 0) return -1;
    if (size == 1) return heap[--size];
    int root = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
    return root;
}

int main() {
    int choice, val;
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            int maxVal = extractMax();
            if (maxVal == -1) printf("Heap is empty\n");
            else printf("%d\n", maxVal);
        } else if (choice == 0) break;
    }
    return 0;
}
