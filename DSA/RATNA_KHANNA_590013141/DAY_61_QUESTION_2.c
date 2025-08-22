#include <stdio.h>

void heapifyDown(int arr[], int n, int i) {
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
        heapifyDown(arr, n, largest);
    }
}

void heapifyUp(int arr[], int i) {
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int insert(int arr[], int n, int value) {
    arr[n] = value;
    heapifyUp(arr, n);
    return n + 1;
}

int deleteRoot(int arr[], int n) {
    if (n <= 0) {
        printf("Heap is empty\n");
        return n;
    }
    arr[0] = arr[n - 1];
    n--;
    heapifyDown(arr, n, 0);
    return n;
}

int main() {
    int heap[100], n = 0, choice, value;
    while (1) {
        printf("\n1. Insert\n2. Delete root\n0. Stop\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            n = insert(heap, n, value);
        } else if (choice == 2) {
            n = deleteRoot(heap, n);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    printf("Heap after operations\n[");
    for (int i = 0; i < n; i++) {
        printf("%d", heap[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    return 0;
}
