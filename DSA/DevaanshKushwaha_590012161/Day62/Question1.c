#include <stdio.h>
#include <stdlib.h>

// Swap utility
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Min-heapify function
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Build Min Heap
void buildMinHeap(int heap[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

// Extract minimum element
int extractMin(int heap[], int *n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
    return min;
}

// Insert into min-heap
void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    int i = *n - 1;
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Function to find minimum cost
int minCost(int arr[], int n) {
    buildMinHeap(arr, n);
    int cost = 0;

    while (n > 1) {
        int first = extractMin(arr, &n);
        int second = extractMin(arr, &n);
        int sum = first + second;
        cost += sum;
        insertHeap(arr, &n, sum);
    }

    return cost;
}

int main() {
    int n;
    printf("Enter number of ropes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter rope lengths: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = minCost(arr, n);
    printf("Minimum cost to connect ropes: %d\n", result);

    return 0;
}
