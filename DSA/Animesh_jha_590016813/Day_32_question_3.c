#include <stdio.h>

int xorArray(int arr[], int size) {
    int result = 0;
    for(int i = 0; i < size; i++) {
        result ^= arr[i]; 
    }
    return result;
}

int main() {
    int arr[] = {4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = xorArray(arr, size);
    printf("XOR of all elements: %d\n", result);

    return 0;
}
