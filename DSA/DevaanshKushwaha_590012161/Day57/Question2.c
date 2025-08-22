#include <stdio.h>
#include <stdlib.h>

int isMaxHeap(int* arr, int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        
        if (leftChild < n && arr[i] < arr[leftChild]) {
            return 0;
        }
        
        if (rightChild < n && arr[i] < arr[rightChild]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = isMaxHeap(arr, n);
    printf("%s\n", result ? "true" : "false");
    
    free(arr);
    return 0;
}
