#include <stdio.h>
#include <stdlib.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

int kthSmallest(int arr[], int n, int k) {
    buildMinHeap(arr, n);
    for (int i = 0; i < k - 1; i++) {
        arr[0] = arr[n - 1];
        n--;
        minHeapify(arr, n, 0);
    }
    return arr[0];
}

int main() {
    int arr1[] = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", kthSmallest(arr1, n1, k1));

    int arr2[] = {7, 10, 4, 20, 15};
    int k2 = 4;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", kthSmallest(arr2, n2, k2));

    return 0;
}
