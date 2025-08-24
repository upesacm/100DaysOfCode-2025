#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Utility swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify Up (for insertion)
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down (for deletion)
void heapifyDown(int i) {
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

// Insert into Max Heap
void insert(int val) {
    heap[size] = val;
    size++;
    heapifyUp(size - 1);
}

// Delete Root (Max element)
void deleteRoot() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Deleted root: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Print Heap
void printHeap() {
    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Delete Root\n3. Print Heap\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                printHeap();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
