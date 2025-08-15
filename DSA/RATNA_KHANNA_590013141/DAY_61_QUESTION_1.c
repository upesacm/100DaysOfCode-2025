#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
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
    printf("Input:\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("arr = [");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    convertMinToMaxHeap(arr, n);
    printf("Output:\nA valid max heap array\narr = [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    return 0;
}
