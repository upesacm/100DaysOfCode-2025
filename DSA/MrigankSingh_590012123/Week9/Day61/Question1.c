#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] < arr[i]) {
            return false;
        }
        
        if (right < n && arr[right] < arr[i]) {
            return false;
        }
    }
    return true;
}

void convertMinToMaxHeap(int arr[], int n) {
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

int* readInputArray(int* n) {
    printf("Enter the elements of the min-heap separated by spaces: ");
    char line[1000];
    fgets(line, sizeof(line), stdin);
    
    int* arr = NULL;
    int capacity = 0;
    *n = 0;
    
    char* token = strtok(line, " ");
    while (token != NULL) {
        if (*n >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
        }
        arr[(*n)++] = atoi(token);
        token = strtok(NULL, " ");
    }
    
    return arr;
}

int main() {
    int n;
    int* arr = readInputArray(&n);
    
    if (n == 0) {
        printf("Empty input array.\n");
        free(arr);
        return 0;
    }
    
    if (!isMinHeap(arr, n)) {
        printf("The input array is not a valid min-heap.\n");
        free(arr);
        return 0;
    }
    
    printf("Input (min-heap): ");
    printArray(arr, n);
    
    convertMinToMaxHeap(arr, n);
    
    printf("Output (max-heap): ");
    printArray(arr, n);
    
    free(arr);
    return 0;
}
