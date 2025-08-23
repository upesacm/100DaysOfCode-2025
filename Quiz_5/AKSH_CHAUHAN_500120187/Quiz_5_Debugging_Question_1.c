#include <stdio.h>

void find_unique_pair(int arr[], int size, int* unique1, int* unique2) {
    int xor_sum = 0;

    // Step 1: XOR all elements to get xor of the two unique numbers
    for (int i = 0; i < size; i++) {
        xor_sum ^= arr[i];
    }

    // Step 2: Find a set bit (rightmost) in xor_sum
    int diff_bit = xor_sum & -xor_sum;

    *unique1 = 0;
    *unique2 = 0;

    // Step 3: Divide numbers into two groups based on diff_bit
    for (int i = 0; i < size; i++) {
        if (arr[i] & diff_bit)
            *unique1 ^= arr[i];
        else
            *unique2 ^= arr[i];
    }
}

int main() {
    int arr[] = {2, 4, 7, 2, 4, 9};  // 7 and 9 are unique
    int size = sizeof(arr) / sizeof(arr[0]);
    int u1, u2;

    find_unique_pair(arr, size, &u1, &u2);
    printf("The two unique numbers are: %d and %d\n", u1, u2);
    return 0;
}
