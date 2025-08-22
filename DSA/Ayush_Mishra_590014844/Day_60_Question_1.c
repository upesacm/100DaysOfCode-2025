#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int extractMin(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}

void insertHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter value of k: ");
    scanf("%d", &k);

    int heap[k + 1], size = 0;
    for (int i = 0; i <= k && i < n; i++)
        insertHeap(heap, &size, arr[i]);

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = extractMin(heap, &size);
        insertHeap(heap, &size, arr[i]);
    }

    while (size > 0)
        arr[index++] = extractMin(heap, &size);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
