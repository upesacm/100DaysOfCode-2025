#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapify(int arr[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) { swap(&arr[i], &arr[smallest]); heapify(arr, n, smallest); }
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}

void insertHeap(int arr[], int *n, int val) {
    int i = (*n)++;
    arr[i] = val;
    while (i > 0 && arr[(i-1)/2] > arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int minCost(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    int cost = 0;
    while (n > 1) {
        int x = extractMin(arr, &n);
        int y = extractMin(arr, &n);
        int sum = x + y;
        cost += sum;
        insertHeap(arr, &n, sum);
    }
    return cost;
}

int main() {
    int arr1[] = {4, 3, 2, 6}, n1 = 4;
    printf("Min cost: %d\n", minCost(arr1, n1)); // 29

    int arr2[] = {1, 2, 3, 4, 5}, n2 = 5;
    printf("Min cost: %d\n", minCost(arr2, n2)); // 33
    return 0;
}
