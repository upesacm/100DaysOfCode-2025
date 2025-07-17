#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], xor_result = 0;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        xor_result ^= arr[i];
    }

    printf("XOR of all elements is: %d\n", xor_result);
    return 0;
}
