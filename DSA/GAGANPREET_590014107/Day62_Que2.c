
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int diff;
    int val;
} Node;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node heap[], int n, int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && (heap[left].diff > heap[largest].diff || 
        (heap[left].diff == heap[largest].diff && heap[left].val > heap[largest].val)))
        largest = left;
    if (right < n && (heap[right].diff > heap[largest].diff || 
        (heap[right].diff == heap[largest].diff && heap[right].val > heap[largest].val)))
        largest = right;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void insertHeap(Node heap[], int *n, Node val, int k) {
    if (*n < k) {
        heap[*n] = val;
        int i = (*n)++;
        while (i > 0 && (heap[(i-1)/2].diff < heap[i].diff || 
               (heap[(i-1)/2].diff == heap[i].diff && heap[(i-1)/2].val < heap[i].val))) {
            swap(&heap[i], &heap[(i-1)/2]);
            i = (i-1)/2;
        }
    } else if (val.diff < heap[0].diff || (val.diff == heap[0].diff && val.val < heap[0].val)) {
        heap[0] = val;
        heapify(heap, *n, 0);
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void kClosestNumbers(int arr[], int n, int target, int k) {
    Node heap[k];
    int size = 0;
    for (int i = 0; i < n; i++) {
        Node node = {abs(arr[i] - target), arr[i]};
        insertHeap(heap, &size, node, k);
    }
    int result[k];
    for (int i = 0; i < k; i++) result[i] = heap[i].val;
    qsort(result, k, sizeof(int), cmp);
    printf("K closest numbers: ");
    for (int i = 0; i < k; i++) printf("%d ", result[i]);
    printf("\n");
}

int main() {
    int n, target, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    printf("Enter k: ");
    scanf("%d", &k);

    kClosestNumbers(arr, n, target, k);

    return 0;
}
