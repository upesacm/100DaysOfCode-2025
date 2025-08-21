#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

void insertHeap(int arr[], int *n, int key) {
    (*n)++;
    int i = *n - 1;
    arr[i] = key;
    while (i != 0 && arr[(i-1)/2] > arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int minCostRopes(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    int cost = 0;
    while (n > 1) {
        int first = extractMin(arr, &n);
        int second = extractMin(arr, &n);
        int newRope = first + second;
        cost += newRope;
        insertHeap(arr, &n, newRope);
    }
    return cost;
}

int main() {
    int arr1[] = {4, 3, 2, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", minCostRopes(arr1, n1));

    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", minCostRopes(arr2, n2));

    return 0;
}