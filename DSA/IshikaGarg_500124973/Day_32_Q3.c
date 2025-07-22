#include <stdio.h>

int xorArray(int arr[], int size) {
    int xor_result = 0;
    for (int i = 0; i < size; i++) {
        xor_result ^= arr[i];
    }
    return xor_result;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    printf("XOR of arr1: %d\n", xorArray(arr1, 3)); 
    printf("XOR of arr2: %d\n", xorArray(arr2, 3)); 
    return 0;
}
