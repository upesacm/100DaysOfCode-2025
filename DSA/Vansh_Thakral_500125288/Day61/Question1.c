#include <stdio.h>

#define MAX 100


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(int arr[], int n) {
    
    for (int i = (n/2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}


void insertMaxHeap(int arr[], int *n, int value) {
    (*n)++;
    int i = *n - 1;
    arr[i] = value;


    while (i != 0 && arr[(i-1)/2] < arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteRootMaxHeap(int arr[], int *n) {
    if (*n <= 0) return;
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
}


void heapSort(int arr[], int n) {

    for (int i = (n/2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }


    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {

    int minHeap[] = {1, 3, 5, 7, 9, 2};
    int n1 = sizeof(minHeap)/sizeof(minHeap[0]);
    printf("Original Min Heap: ");
    printArray(minHeap, n1);
    convertMinToMaxHeap(minHeap, n1);
    printf("Converted Max Heap: ");
    printArray(minHeap, n1);


    int heap[MAX];
    int n2 = 0;
    insertMaxHeap(heap, &n2, 20);
    insertMaxHeap(heap, &n2, 15);
    insertMaxHeap(heap, &n2, 8);
    printf("Heap after insertions: ");
    printArray(heap, n2);
    deleteRootMaxHeap(heap, &n2);
    printf("Heap after deleting root: ");
    printArray(heap, n2);

    insertMaxHeap(heap, &n2, 30);
    insertMaxHeap(heap, &n2, 25);
    insertMaxHeap(heap, &n2, 10);
    insertMaxHeap(heap, &n2, 35);
    deleteRootMaxHeap(heap, &n2);
    insertMaxHeap(heap, &n2, 40);
    printf("Heap after more operations: ");
    printArray(heap, n2);


    int arr[] = {4, 10, 3, 5, 1};
    int n3 = sizeof(arr)/sizeof(arr[0]);
    printf("Original array for Heap Sort: ");
    printArray(arr, n3);
    heapSort(arr, n3);
    printf("Sorted array using Heap Sort: ");
    printArray(arr, n3);

    return 0;
}

