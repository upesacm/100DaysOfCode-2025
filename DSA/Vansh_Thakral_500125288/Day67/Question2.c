#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
void heapify(int heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}
int extractMin(int heap[], int *n) {
    int root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}
void insertHeap(int heap[], int *n, int val) {
    int i = (*n)++;
    heap[i] = val;
    while (i && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int minCost(int ropes[], int n) {

    for (int i = n/2-1; i >= 0; i--)
        heapify(ropes, n, i);

    int cost = 0;
    while (n > 1) {
        int first = extractMin(ropes, &n);
        int second = extractMin(ropes, &n);
        int newRope = first + second;
        cost += newRope;
        insertHeap(ropes, &n, newRope);
    }
    return cost;
}

int main() {
    int ropes[] = {4, 3, 2, 6};
    int n = sizeof(ropes) / sizeof(ropes[0]);

    printf("Minimum Cost = %d\n", minCost(ropes, n));
    return 0;
}

