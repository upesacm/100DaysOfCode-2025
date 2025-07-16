#include <stdio.h>
#include <stdlib.h>

int find_non_repeating(int *arr, int size) {
    if (size == 1) return arr[0];
    
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
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    while (getchar() != '\n');

    int result = find_non_repeating(arr, size);
    printf("Non-repeating element: %d\n", result);

    free(arr);
    return 0;
}