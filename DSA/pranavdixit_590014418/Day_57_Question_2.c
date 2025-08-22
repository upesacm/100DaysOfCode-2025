#include <stdio.h>

int isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2 * i + 1 < n && arr[i] < arr[2 * i + 1])
            return 0;
        if (2 * i + 2 < n && arr[i] < arr[2 * i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int arr1[] = {90, 15, 10, 7, 12, 2};
    int arr2[] = {9, 15, 10, 7, 12, 2};

    printf("%s\n", isMaxHeap(arr1, 6) ? "true" : "false");
    printf("%s\n", isMaxHeap(arr2, 6) ? "true" : "false");

    return 0;
}
