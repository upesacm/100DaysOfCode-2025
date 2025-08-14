#include <stdio.h>
#include <stdbool.h>

bool isMaxHeap(int *arr, int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (leftChild < n && arr[i] < arr[leftChild]) {
            return false;
        }
        if (rightChild < n && arr[i] < arr[rightChild]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {90, 15, 10, 7, 12, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%s\n", isMaxHeap(arr1, n1) ? "true" : "false");

    int arr2[] = {9, 15, 10, 7, 12, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%s\n", isMaxHeap(arr2, n2) ? "true" : "false");

    return 0;
}
