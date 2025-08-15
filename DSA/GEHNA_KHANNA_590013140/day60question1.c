#include <stdio.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < heapSize && heap[l] < heap[smallest]) smallest = l;
    if (r < heapSize && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void push(int val) {
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

int pop() {
    if (heapSize <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);

    int idx = 0;
    for (int i = 0; i <= k && i < n; i++) push(arr[i]);
    for (int i = k + 1; i < n; i++) {
        arr[idx++] = pop();
        push(arr[i]);
    }
    while (heapSize > 0) arr[idx++] = pop();

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
