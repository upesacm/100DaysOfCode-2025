#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void processArrayAndString(int* arr, int n, char* str, int* sum, int* vowel_count) {
    *sum = 0;
    *vowel_count = 0;

    // Calculate sum of positive numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            *sum += arr[i];
        }
    }

    // Count vowels in string (case-insensitive)
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            (*vowel_count)++;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer for array size.\n");
        return 1;
    }

    // Dynamically allocate array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL && n > 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i);
            scanf("%d", &arr[i]);
        }
    }

    // Clear input buffer
    while (getchar() != '\n');

    char str[1000];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

    int sum, vowel_count;
    processArrayAndString(arr, n, str, &sum, &vowel_count);

    printf("Sum: %d, Vowels: %d\n", sum, vowel_count);

    free(arr);
    return 0;
}
