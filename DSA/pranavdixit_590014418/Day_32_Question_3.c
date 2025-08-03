#include <stdio.h>

int xorAll(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main() {
    int arr[] = {4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = xorAll(arr, n);

    printf("XOR of All Elements: %d\n", result);
    return 0;
}
