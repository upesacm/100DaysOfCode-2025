#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        int temp = arr[i]; arr[i] = arr[smallest]; arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}

void insertHeap(int arr[], int *n, int val) {
    arr[(*n)++] = val;
    for (int i = (*n - 1); i > 0 && arr[(i-1)/2] > arr[i]; i = (i-1)/2) {
        int temp = arr[i]; arr[i] = arr[(i-1)/2]; arr[(i-1)/2] = temp;
    }
}

int minCostRopes(int arr[], int n) {
    // Build min-heap
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);

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
    int arr1[] = {4, 3, 2, 6};
    int n1 = 4;
    printf("Min cost ropes (Ex1): %d\n", minCostRopes(arr1, n1)); // 29

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = 5;
    printf("Min cost ropes (Ex2): %d\n", minCostRopes(arr2, n2)); // 33

    return 0;
}

