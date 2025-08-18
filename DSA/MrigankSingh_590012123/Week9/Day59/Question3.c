#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum { MAX_HEAP, MIN_HEAP } HeapType;

bool isHeap(int arr[], int n, HeapType type) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (type == MAX_HEAP) {
            if ((left < n && arr[left] > arr[i]) || 
                (right < n && arr[right] > arr[i])) {
                return false;
            }
        } else { // MIN_HEAP
            if ((left < n && arr[left] < arr[i]) || 
                (right < n && arr[right] < arr[i])) {
                return false;
            }
        }
    }
    return true;
}

bool areHeapsIdentical(int arr1[], int n1, int arr2[], int n2, HeapType type) {
    if (n1 != n2) return false;
    
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    
    return isHeap(arr1, n1, type) && isHeap(arr2, n2, type);
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

int main() {
    int n1, n2;
    HeapType type;
    
    printf("Enter heap type (0 for max-heap, 1 for min-heap): ");
    scanf("%d", &type);
    
    printf("Enter size of first heap: ");
    scanf("%d", &n1);
    int* arr1 = (int*)malloc(n1 * sizeof(int));
    printf("Enter elements of first heap: ");
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);
    
    printf("Enter size of second heap: ");
    scanf("%d", &n2);
    int* arr2 = (int*)malloc(n2 * sizeof(int));
    printf("Enter elements of second heap: ");
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);
    
    printf("\nFirst heap: ");
    printArray(arr1, n1);
    printf("\nSecond heap: ");
    printArray(arr2, n2);
    
    bool identical = areHeapsIdentical(arr1, n1, arr2, n2, type);
    printf("\nThe heaps are %sidentical\n", identical ? "" : "not ");
    
    free(arr1);
    free(arr2);
    return 0;
}
