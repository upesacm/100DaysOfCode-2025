#include <stdio.h>
#include <stdlib.h>

int compute_array_xor(int *arr, int size) {
    if (arr == NULL || size < 1) return 0;
    
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int size;
    printf("Enter array size (positive integer): ");
    if (scanf("%d", &size) != 1 || size < 1) {
        fprintf(stderr, "Error: Invalid array size.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: Invalid input at element %d.\n", i+1);
            free(arr);
            return 1;
        }
    }

    while (getchar() != '\n');

    int result = compute_array_xor(arr, size);
    printf("XOR of array elements: %d\n", result);

    free(arr);
    return 0;
}