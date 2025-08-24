#include <stdio.h>
#include <stdlib.h>

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_down(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(heap, n, smallest);
    }
}

void heapify_up(int heap[], int i) {
    if (i && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        heapify_up(heap, (i - 1) / 2);
    }
}

int extractMin(int heap[], int *n) {
    if (*n <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[--(*n)];
    heapify_down(heap, *n, 0);
    return root;
}

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    heapify_up(heap, *n - 1);
}

// Function to sort k-sorted array
void sortKSortedArray(int arr[], int n, int k) {
    int heap[k + 1], heapSize = 0;
    int index = 0;

    // Insert first k+1 elements into heap
    for (int i = 0; i < k + 1 && i < n; i++)
        insertHeap(heap, &heapSize, arr[i]);

    // Process remaining elements
    for (int i = k + 1; i < n; i++) {
        arr[index++] = extractMin(heap, &heapSize);
        insertHeap(heap, &heapSize, arr[i]);
    }

    // Extract remaining elements from heap
    while (heapSize > 0)
        arr[index++] = extractMin(heap, &heapSize);
}

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of k: ");
    scanf("%d", &k);

    sortKSortedArray(arr, n, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
