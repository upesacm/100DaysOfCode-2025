#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void kLargest(int arr[], int n, int k) {
    int heap[k];
    for (int i = 0; i < k; i++)
        heap[i] = arr[i];

    buildMinHeap(heap, k);

    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            heapify(heap, k, 0);
        }
    }

    printf("K largest elements: ");
    for (int i = k - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapify(heap, i, 0);
        printf("%d ", temp);
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    kLargest(arr, n, k);
    return 0;
}
