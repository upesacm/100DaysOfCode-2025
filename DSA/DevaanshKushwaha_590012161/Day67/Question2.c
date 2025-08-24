#include <stdio.h>
#include <stdlib.h>

void heapify(int heap[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, n, smallest);
    }
}

int extractMin(int heap[], int* n) {
    int root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}

void insertHeap(int heap[], int* n, int val) {
    int i = (*n)++;
    heap[i] = val;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int minCost(int ropes[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(ropes, n, i);

    int cost = 0;
    while (n > 1) {
        int a = extractMin(ropes, &n);
        int b = extractMin(ropes, &n);
        int sum = a + b;
        cost += sum;
        insertHeap(ropes, &n, sum);
    }
    return cost;
}

int main() {
    int n;
    printf("Enter number of ropes: ");
    scanf("%d", &n);

    int ropes[n];
    printf("Enter rope lengths:\n");
    for (int i = 0; i < n; i++) scanf("%d", &ropes[i]);

    printf("Minimum cost: %d\n", minCost(ropes, n));
    return 0;
}
