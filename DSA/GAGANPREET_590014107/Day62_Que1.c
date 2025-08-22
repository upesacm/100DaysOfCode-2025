
#include <stdio.h>
#include <stdlib.h>

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && heap[left] < heap[smallest]) smallest = left;
    if (right < n && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, n, smallest);
    }
}

int extractMin(int heap[], int *n) {
    int minVal = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return minVal;
}

void insertHeap(int heap[], int *n, int val) {
    int i = (*n)++;
    heap[i] = val;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int minCostToConnectRopes(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
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
    int n;
    printf("Enter number of ropes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter lengths of ropes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minCostToConnectRopes(arr, n);
    printf("Minimum cost to connect ropes: %d\n", result);

    return 0;
}
