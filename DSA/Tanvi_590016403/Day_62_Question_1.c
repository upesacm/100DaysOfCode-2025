#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// -------------------- MIN HEAP (for Connect Ropes) --------------------
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyMin(int heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && heap[l] < heap[smallest])
        smallest = l;
    if (r < n && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyMin(heap, n, smallest);
    }
}

int extractMin(int heap[], int *n) {
    if (*n <= 0) return INT_MAX;
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyMin(heap, *n, 0);
    return root;
}

void insertMinHeap(int heap[], int *n, int val) {
    (*n)++;
    int i = *n - 1;
    heap[i] = val;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 1. Connect N Ropes with Minimum Cost
int connectRopes(int arr[], int n) {
    int heap[n], size = n;
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    for (int i = n / 2 - 1; i >= 0; i--) heapifyMin(heap, n, i);

    int cost = 0;
    while (size > 1) {
        int first = extractMin(heap, &size);
        int second = extractMin(heap, &size);
        int sum = first + second;
        cost += sum;
        insertMinHeap(heap, &size, sum);
    }
    return cost;
}

// -------------------- MAX HEAP (for K closest numbers) --------------------
typedef struct {
    int diff;
    int value;
} Node;

void heapifyMax(Node heap[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && heap[l].diff > heap[largest].diff) largest = l;
    if (r < n && heap[r].diff > heap[largest].diff) largest = r;

    if (largest != i) {
        Node t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        heapifyMax(heap, n, largest);
    }
}

// 2. K Closest Numbers
void kClosestNumbers(int arr[], int n, int target, int k) {
    Node heap[k];
    int size = 0;

    for (int i = 0; i < n; i++) {
        Node node = { abs(arr[i] - target), arr[i] };

        if (size < k) {
            heap[size++] = node;
            for (int j = size / 2 - 1; j >= 0; j--) heapifyMax(heap, size, j);
        } else if (node.diff < heap[0].diff) {
            heap[0] = node;
            heapifyMax(heap, size, 0);
        }
    }

    printf("K Closest Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i].value);
    }
    printf("\n");
}

// -------------------- Kth Largest Subarray Sum --------------------
int kthLargestSubarraySum(int arr[], int n, int k) {
    int prefix[n+1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];

    int *heap = (int*)malloc(k * sizeof(int));
    int size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int sum = prefix[j] - prefix[i];

            if (size < k) {
                heap[size++] = sum;
                for (int m = size / 2 - 1; m >= 0; m--) heapifyMin(heap, size, m);
            } else if (sum > heap[0]) {
                heap[0] = sum;
                heapifyMin(heap, size, 0);
            }
        }
    }

    int ans = heap[0];
    free(heap);
    return ans;
}

// -------------------- MAIN --------------------
int main() {
    // Problem 1
    int ropes[] = {4, 3, 2, 6};
    int n1 = sizeof(ropes)/sizeof(ropes[0]);
    printf("Minimum Cost to Connect Ropes: %d\n", connectRopes(ropes, n1));

    // Problem 2
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    kClosestNumbers(arr2, n2, 3, 2);

    // Problem 3
    int arr3[] = {10, -10, 20, -40};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("Kth Largest Subarray Sum: %d\n", kthLargestSubarraySum(arr3, n3, 3));

    return 0;
}
