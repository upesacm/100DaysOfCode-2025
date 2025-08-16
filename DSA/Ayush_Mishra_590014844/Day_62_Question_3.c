#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    int i = *n;
    (*n)++;
    while (i != 0 && heap[(i - 1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void extractMin(int heap[], int *n) {
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
}

int main() {
    int arr[1000], n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);

    int heap[1000], size = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (size < k)
                insertHeap(heap, &size, sum);
            else if (sum > heap[0]) {
                extractMin(heap, &size);
                insertHeap(heap, &size, sum);
            }
        }
    }

    printf("%d\n", heap[0]);
    return 0;
}
