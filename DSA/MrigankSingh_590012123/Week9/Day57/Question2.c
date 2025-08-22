#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[i]) {
            return false;
        }
        
        if (right < n && arr[right] > arr[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Invalid input. Number of elements must be non-negative.\n");
        return 1;
    }
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements of the array (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bool result = isMaxHeap(arr, n);
    printf("The array %s a max-heap.\n", result ? "is" : "is not");
    
    free(arr);
    return 0;
}
