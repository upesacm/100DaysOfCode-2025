#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n, k;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("enter value of k \n");
    scanf("%d", &k);
    int heap[k];
    for (int i = 0; i < k; i++) heap[i] = arr[i];
    buildHeap(heap, k);
    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            heapify(heap, k, 0);
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapify(heap, i, 0);
    }
    for (int i = 0; i < k; i++) printf("%d ", heap[i]);
    return 0;
}
