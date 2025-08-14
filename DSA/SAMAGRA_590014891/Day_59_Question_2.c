#include <stdio.h>

#define MAX 100
int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] < heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void bubbleDown(int i) {
    int left, right, largest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;
        if (largest != i) {
            swap(&heap[largest], &heap[i]);
            i = largest;
        } else break;
    }
}

void insert(int val) {
    if (size >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    heap[size] = val;
    size++;
    bubbleUp(size - 1);
}

int extractMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    bubbleDown(0);
    return max;
}

int main() {
    int choice, val, n, i;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n1. Insert\n2. Extract Max\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            int maxVal = extractMax();
            if (maxVal != -1)
                printf("Extracted Max: %d\n", maxVal);
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
