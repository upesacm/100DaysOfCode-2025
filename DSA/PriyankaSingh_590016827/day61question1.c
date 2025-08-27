#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n;
    printf("Enter size of heap: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of Min Heap:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    convertMinToMaxHeap(arr, n);

    printf("Converted Max Heap:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
