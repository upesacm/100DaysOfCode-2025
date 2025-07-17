#include <stdio.h>

int xorAll(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];  
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = xorAll(arr, n);
    printf("XOR of all elements: %d\n", result);
    return 0;
}
