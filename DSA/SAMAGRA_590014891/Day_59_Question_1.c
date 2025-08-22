#include <stdio.h>

#define MAX 100
int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void bubbleDown(int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;
        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        } else break;
    }
}

void insert(int value) {
    if (size >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    heap[size] = value;
    size++;
    bubbleUp(size - 1);
}

int extractMin() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    bubbleDown(0);
    return min;
}

int main() {
    int choice, val, n, i;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n1. Insert\n2. Extract Min\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            int minVal = extractMin();
            if (minVal != -1)
                printf("Extracted Min: %d\n", minVal);
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
