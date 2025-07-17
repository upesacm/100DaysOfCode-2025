#include <stdio.h>

int findUnique(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i]; 
    }
    return result;
}

int main() {
    int arr[] = {5, 1, 1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int unique = findUnique(arr, n);
    printf("Unique element: %d\n", unique);
    return 0;
}
