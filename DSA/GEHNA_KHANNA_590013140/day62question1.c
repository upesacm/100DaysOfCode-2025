#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int smallest = i, l = 2*i, r = 2*i+1;
    if (l <= n && arr[l] < arr[smallest]) smallest = l;
    if (r <= n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        heapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int *n) {
    int root = arr[1];
    arr[1] = arr[*n];
    (*n)--;
    heapify(arr, *n, 1);
    return root;
}

void insertHeap(int arr[], int *n, int val) {
    (*n)++;
    arr[*n] = val;
    int i = *n;
    while (i > 1 && arr[i/2] > arr[i]) {
        int t = arr[i]; arr[i] = arr[i/2]; arr[i/2] = t;
        i /= 2;
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for (int i=1;i<=n;i++) scanf("%d", &arr[i]);
    for (int i=n/2;i>=1;i--) heapify(arr, n, i);
    int cost=0;
    while (n > 1) {
        int a = extractMin(arr, &n);
        int b = extractMin(arr, &n);
        cost += a+b;
        insertHeap(arr, &n, a+b);
    }
    printf("%d", cost);
    return 0;
}
