#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator for sorting numbers as strings
int compare(const void *a, const void *b) {
    char ab[50], ba[50];
    sprintf(ab, "%s%s", *(char **)a, *(char **)b);
    sprintf(ba, "%s%s", *(char **)b, *(char **)a);
    return strcmp(ba, ab); // descending order
}

char* largestNumber(char* nums[], int n) {
    qsort(nums, n, sizeof(char*), compare);

    // handle case where numbers are all "0"
    if (strcmp(nums[0], "0") == 0) return "0";

    static char result[1000] = "";
    result[0] = '\0';
    for (int i = 0; i < n; i++) strcat(result, nums[i]);
    return result;
}

int main() {
    char* arr1[] = {"10", "2"};
    printf("Largest Number: %s\n", largestNumber(arr1, 2)); // "210"

    char* arr2[] = {"3","30","34","5","9"};
    printf("Largest Number: %s\n", largestNumber(arr2, 5)); // "9534330"
    return 0;
}
