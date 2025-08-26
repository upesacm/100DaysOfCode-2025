#include <stdio.h>
#include <stdlib.h>

// Structure to store number and its distance from target
typedef struct {
    int value;
    int dist;
} Node;

// Swap utility
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

// Max-heapify based on distance
void maxHeapify(Node heap[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left].dist > heap[largest].dist)
        largest = left;
    if (right < n && heap[right].dist > heap[largest].dist)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

// Insert into max heap
void insertHeap(Node heap[], int *n, Node newNode) {
    heap[*n] = newNode;
    (*n)++;
    int i = *n - 1;
    while (i > 0 && heap[(i-1)/2].dist < heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Remove max element
void removeMax(Node heap[], int *n) {
    heap[0] = heap[*n - 1];
    (*n)--;
    maxHeapify(heap, *n, 0);
}

// Find k closest numbers
void kClosest(int arr[], int n, int target, int k) {
    Node heap[n];
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        Node node;
        node.value = arr[i];
        node.dist = abs(arr[i] - target);

        insertHeap(heap, &heapSize, node);

        if (heapSize > k) {
            removeMax(heap, &heapSize);
        }
    }

    printf("K closest numbers: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].value);
    }
    printf("\n");
}

int main() {
    int n, target, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    printf("Enter k: ");
    scanf("%d", &k);

    kClosest(arr, n, target, k);

    return 0;
}
