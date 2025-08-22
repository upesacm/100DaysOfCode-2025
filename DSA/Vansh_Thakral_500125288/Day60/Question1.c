#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    if (i && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        heapifyUp(heap, (i-1)/2);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

void sortKSortedArray(int arr[], int n, int k) {
    int heap[k+1], size = 0;

    
    for (int i = 0; i <= k && i < n; i++)
        push(heap, &size, arr[i]);

    int idx = 0;
    for (int i = k+1; i < n; i++) {
        arr[idx++] = pop(heap, &size);
        push(heap, &size, arr[i]);
    }
    while (size > 0)
        arr[idx++] = pop(heap, &size);
}


int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    sortKSortedArray(arr, n, k);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
