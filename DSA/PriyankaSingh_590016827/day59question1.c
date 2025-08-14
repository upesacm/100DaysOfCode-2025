#include <stdio.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        bubbleDown(smallest);
    }
}

void insert(int value) {
    if (heapSize == MAX) {
        printf("Heap is full!\n");
        return;
    }
    heap[heapSize] = value;
    bubbleUp(heapSize);
    heapSize++;
}

int extractMin() {
    if (heapSize <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    bubbleDown(0);
    return root;
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Extract Min\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
        } else if (choice == 2) {
            int min = extractMin();
            if (min != -1)
                printf("Extracted Min: %d\n", min);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
