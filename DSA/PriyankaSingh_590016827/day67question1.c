#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function for custom comparison
int compareStrings(const void* a, const void* b) {
    char* str_a = *(char**)a;
    char* str_b = *(char**)b;
    char ab[20], ba[20];
    sprintf(ab, "%s%s", str_a, str_b);
    sprintf(ba, "%s%s", str_b, str_a);
    return strcmp(ba, ab);
}

// Function to find the largest number from an array
char* largestNumber(int* nums, int numsSize) {
    char** s_nums = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        s_nums[i] = (char*)malloc(10 * sizeof(char));
        sprintf(s_nums[i], "%d", nums[i]);
    }

    qsort(s_nums, numsSize, sizeof(char*), compareStrings);

    if (strcmp(s_nums[0], "0") == 0) {
        return "0";
    }

    int total_len = 0;
    for (int i = 0; i < numsSize; i++) {
        total_len += strlen(s_nums[i]);
    }

    char* result = (char*)malloc((total_len + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, s_nums[i]);
    }

    for (int i = 0; i < numsSize; i++) {
        free(s_nums[i]);
    }
    free(s_nums);

    return result;
}

int main() {
    // Example 1
    int nums1[] = {10, 2};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Largest number: %s\n", largestNumber(nums1, n1));

    // Example 2
    int nums2[] = {3, 30, 34, 5, 9};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Largest number: %s\n", largestNumber(nums2, n2));

    return 0;
}
