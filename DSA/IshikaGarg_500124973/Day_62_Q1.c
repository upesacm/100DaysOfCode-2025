#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    int parent = (i-1)/2;
    if (i > 0 && heap[i] < heap[parent]) {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

int extractMin(int heap[], int *n) {
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
    return root;
}

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    heapifyUp(heap, *n - 1);
}

int minCostToConnectRopes(int ropes[], int n) {
    // Build heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyDown(ropes, n, i);
    
    int totalCost = 0;
    
    while (n > 1) {
        int first = extractMin(ropes, &n);
        int second = extractMin(ropes, &n);
        
        int cost = first + second;
        totalCost += cost;
        
        insertHeap(ropes, &n, cost);
    }
    
    return totalCost;
}

int main() {
    int ropes1[] = {4, 3, 2, 6};
    int n1 = 4;
    printf("%d\n", minCostToConnectRopes(ropes1, n1)); 

    int ropes2[] = {1, 2, 3, 4, 5};
    int n2 = 5;
    printf("%d\n", minCostToConnectRopes(ropes2, n2)); 
    return 0;
}
