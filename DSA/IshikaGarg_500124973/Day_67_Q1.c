#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparator for qsort
int compare(const void *a, const void *b) {
    char ab[50], ba[50];
    sprintf(ab, "%s%s", *(char **)a, *(char **)b);
    sprintf(ba, "%s%s", *(char **)b, *(char **)a);
    return strcmp(ba, ab); // Descending order
}

void largestNumber(int arr[], int n) {
    char *nums[n];
    for (int i = 0; i < n; i++) {
        nums[i] = (char *)malloc(20);
        sprintf(nums[i], "%d", arr[i]);
    }

    qsort(nums, n, sizeof(char *), compare);

    // Edge case: all zeros
    if (strcmp(nums[0], "0") == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%s", nums[i]);
        free(nums[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {10, 2};
    int arr2[] = {3, 30, 34, 5, 9};

    printf("Example 1: ");
    largestNumber(arr1, 2);  // Output: 210

    printf("Example 2: ");
    largestNumber(arr2, 5);  // Output: 9534330

    return 0;
}

