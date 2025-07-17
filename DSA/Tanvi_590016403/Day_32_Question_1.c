#include <stdio.h>

// Function 1: Swap two numbers using XOR
void swapXOR(int *a, int *b) {
    if (a != b) { // check to avoid 0 result if both pointers are same
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

// Function 2: Find the only non-repeating element using XOR
int findUnique(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

// Function 3: Find XOR of all elements in array
int findXOR(int arr[], int size) {
    int xor_result = 0;
    for (int i = 0; i < size; i++) {
        xor_result ^= arr[i];
    }
    return xor_result;
}

// Main function to test the above functions
int main() {
    // Test for swapXOR
    int a = 4, b = 7;
    printf("Before Swap: a = %d, b = %d\n", a, b);
    swapXOR(&a, &b);
    printf("After Swap: a = %d, b = %d\n\n", a, b);

    // Test for findUnique
    int arr1[] = {2, 3, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Unique element: %d\n\n", findUnique(arr1, size1));

    int arr2[] = {5, 1, 1, 5, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Unique element: %d\n\n", findUnique(arr2, size2));

    // Test for findXOR
    int arr3[] = {1, 2, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("XOR of all elements: %d\n\n", findXOR(arr3, size3));

    int arr4[] = {4, 5, 6};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("XOR of all elements: %d\n", findXOR(arr4, size4));

    return 0;
}
