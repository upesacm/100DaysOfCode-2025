#include <stdio.h>

void findUniquePair(int arr[], int n, int* num1, int* num2) {
    int xor_sum = 0;
    
    // Step 1: XOR all elements
    for (int i = 0; i < n; i++) {
        xor_sum ^= arr[i];
    }

    // Step 2: Isolate the rightmost set bit
    int diff_bit = xor_sum & -xor_sum;

    *num1 = 0;
    *num2 = 0;

    // Step 3: Divide into two groups and XOR separately
    for (int i = 0; i < n; i++) {
        if (arr[i] & diff_bit)
            *num1 ^= arr[i];
        else
            *num2 ^= arr[i];
    }
}

int main() {
    int arr[] = {2, 4, 7, 9, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num1, num2;

    findUniquePair(arr, n, &num1, &num2);

    printf("The two unique numbers are: %d and %d\n", num1, num2);

    return 0;
}
