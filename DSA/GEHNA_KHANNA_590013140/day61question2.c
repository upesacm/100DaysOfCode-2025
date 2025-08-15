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
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else break;
    }
}

void siftDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;
    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        siftDown(largest);
    }
}

void insert(int value) {
    heap[heapSize] = value;
    bubbleUp(heapSize);
    heapSize++;
}

void deleteRoot() {
    if (heapSize == 0) return;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    siftDown(0);
}

void printHeap() {
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Delete Root\n3. Print Heap\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
        } 
        else if (choice == 2) {
            deleteRoot();
        }
        else if (choice == 3) {
            printHeap();
        }
        else if (choice == 4) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
