#include <stdio.h>
#define MAX 100

int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void bubbleDown(int i) {
    int left, right, smallest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;
        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int val) {
    heap[size] = val;
    size++;
    bubbleUp(size - 1);
}

int extractMin() {
    if (size == 0) return -1;
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    bubbleDown(0);
    return min;
}

int main() {
    int choice, val;
    while (1) {
        printf("1.Insert 2.ExtractMin 3.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            printf("%d\n", extractMin());
        } else break;
    }
    return 0;
}
