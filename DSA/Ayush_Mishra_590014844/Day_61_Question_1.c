#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void convertToMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

int main() {
    int n;
    printf("Enter number of elements in min heap: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of min heap:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    convertToMaxHeap(arr, n);

    printf("Max Heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
