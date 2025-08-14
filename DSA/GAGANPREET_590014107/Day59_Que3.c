#include <stdio.h>
#include <stdbool.h>

bool isMaxHeap(int *arr, int n, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    bool isHeap = true;

    if (left < n) {
        if (arr[index] < arr[left]) {
            isHeap = false;
        }
        isHeap = isHeap && isMaxHeap(arr, n, left);
    }
    if (right < n) {
        if (arr[index] < arr[right]) {
            isHeap = false;
        }
        isHeap = isHeap && isMaxHeap(arr, n, right);
    }
    return isHeap;
}

bool areHeapsIdentical(int *arr1, int *arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return isMaxHeap(arr1, n, 0) && isMaxHeap(arr2, n, 0);
}

int main() {
    int arr1[] = {10, 9, 8};
    int arr2[] = {10, 9, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    if (areHeapsIdentical(arr1, arr2, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    int arr3[] = {10, 9, 8};
    int arr4[] = {10, 8, 9};
    
    if (areHeapsIdentical(arr3, arr4, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
