#include <stdio.h>
#include <stdlib.h>

// Helper functions for min-heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }

    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    int i = (n / 2) - 1;
    for (; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int extractMin(int arr[], int* n) {
    int min = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return min;
}

void insertMinHeap(int arr[], int* n, int val) {
    (*n)++;
    int i = *n - 1;
    arr[i] = val;
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to find minimum cost to connect ropes
int minCost(int ropes[], int n) {
    buildMinHeap(ropes, n);
    int total_cost = 0;
    int heap_size = n;

    while (heap_size > 1) {
        int first = extractMin(ropes, &heap_size);
        int second = extractMin(ropes, &heap_size);
        int new_rope = first + second;
        total_cost += new_rope;
        insertMinHeap(ropes, &heap_size, new_rope);
    }
    return total_cost;
}

int main() {
    // Example 1
    int ropes1[] = {4, 3, 2, 6};
    int n1 = sizeof(ropes1) / sizeof(ropes1[0]);
    printf("Minimum cost to connect ropes: %d\n", minCost(ropes1, n1));

    // Example 2
    int ropes2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(ropes2) / sizeof(ropes2[0]);
    printf("Minimum cost to connect ropes: %d\n", minCost(ropes2, n2));

    return 0;
}
