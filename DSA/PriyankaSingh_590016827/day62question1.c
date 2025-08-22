#include <stdio.h>
#include <stdlib.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        int temp = arr[i]; arr[i] = arr[smallest]; arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[*n-1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}

void insertMinHeap(int arr[], int *n, int key) {
    (*n)++;
    int i = *n - 1;
    arr[i] = key;
    while (i != 0 && arr[(i-1)/2] > arr[i]) {
        int temp = arr[i]; arr[i] = arr[(i-1)/2]; arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int connectRopes(int arr[], int n) {
    for (int i = n/2-1; i >= 0; i--) minHeapify(arr, n, i);
    int cost = 0;
    while (n > 1) {
        int x = extractMin(arr, &n);
        int y = extractMin(arr, &n);
        cost += x + y;
        insertMinHeap(arr, &n, x+y);
    }
    return cost;
}

int main() {
    int n;
    printf("Enter number of ropes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter rope lengths:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Minimum cost to connect ropes: %d\n", connectRopes(arr, n));
    return 0;
}
