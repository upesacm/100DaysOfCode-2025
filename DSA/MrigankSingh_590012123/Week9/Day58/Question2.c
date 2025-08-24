#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        siftDown(arr, n, largest);
    }
}

void heapify(int arr[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        siftDown(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[i] < arr[left]) {
            return 0;
        }
        
        if (right < n && arr[i] < arr[right]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr, n);
    
    heapify(arr, n);
    
    printf("Heapified array (max-heap): ");
    printArray(arr, n);
    
    if (isMaxHeap(arr, n)) {
        printf("The array is a valid max-heap.\n");
    } else {
        printf("The array is not a valid max-heap.\n");
    }
    
    free(arr);
    return 0;
}
