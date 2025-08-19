#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void heapifyDown(int arr[], int n, int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

void heapifyUp(int arr[], int i) {
    int parent = (i-1)/2;
    if (i > 0 && arr[i] > arr[parent]) {
        swap(&arr[i], &arr[parent]);
        heapifyUp(arr, parent);
    }
}

int insert(int arr[], int n, int key) {
    arr[n] = key;
    heapifyUp(arr, n);
    return n+1;
}

int deleteRoot(int arr[], int n) {
    if (n <= 0) return n;
    arr[0] = arr[n-1];
    n--;
    heapifyDown(arr, n, 0);
    return n;
}

int main() {
    int arr[100], n = 0, choice, val;
    while (1) {
        printf("\n1. Insert\n2. Delete Root\n3. Display Heap\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            n = insert(arr, n, val);
        } else if (choice == 2) {
            n = deleteRoot(arr, n);
        } else if (choice == 3) {
            printf("Heap: ");
            for (int i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        } else break;
    }
    return 0;
}
