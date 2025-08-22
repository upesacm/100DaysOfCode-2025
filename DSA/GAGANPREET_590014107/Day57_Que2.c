#include <stdio.h>
#include <stdbool.h>


bool isMaxHeap(int arr[], int n) {
    
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        
        if (left < n && arr[i] < arr[left])
            return false;

        
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

int main() {
    
    int arr1[] = {90, 15, 10, 7, 12, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Is arr1 a max-heap? %s\n", isMaxHeap(arr1, n1) ? "true" : "false");

    
    int arr2[] = {9, 15, 10, 7, 12, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Is arr2 a max-heap? %s\n", isMaxHeap(arr2, n2) ? "true" : "false");

    return 0;
}
