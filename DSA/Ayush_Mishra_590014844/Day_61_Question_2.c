#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] > heap[largest])
        largest = l;
    if (r < size && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest);
    }
}

void deleteRoot() {
    if (size == 0)
        return;
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Delete Root\n3. Display Heap\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            deleteRoot();
            printf("Root deleted.\n");
        } else if (choice == 3) {
            printf("Heap: ");
            for (int i = 0; i < size; i++)
                printf("%d ", heap[i]);
            printf("\n");
        } else {
            break;
        }
    }
    return 0;
}
