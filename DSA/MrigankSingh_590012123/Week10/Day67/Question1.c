#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Safer comparison function with dynamic string allocation
int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    
    // Calculate required string lengths
    int len1 = snprintf(NULL, 0, "%d", x);
    int len2 = snprintf(NULL, 0, "%d", y);
    
    // Allocate memory for concatenated strings
    char* ab = (char*)malloc(len1 + len2 + 1);
    char* ba = (char*)malloc(len1 + len2 + 1);
    
    sprintf(ab, "%d%d", x, y);
    sprintf(ba, "%d%d", y, x);
    
    int result = strcmp(ba, ab);
    
    free(ab);
    free(ba);
    return result;
}

char* largestNumber(int arr[], int n) {
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        nums[i] = arr[i];
    }
    
    qsort(nums, n, sizeof(int), compare);
    
    // Check if all numbers are zero
    int allZero = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            allZero = 0;
            break;
        }
    }
    
    if (allZero) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        free(nums);
        return result;
    }
    
    // Calculate total length needed
    int totalLen = 0;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        do {
            totalLen++;
            num /= 10;
        } while (num > 0);
    }
    
    char* result = (char*)malloc((totalLen + 1) * sizeof(char));
    int pos = 0;
    
    for (int i = 0; i < n; i++) {
        pos += sprintf(result + pos, "%d", nums[i]);
    }
    result[pos] = '\0';
    
    free(nums);
    return result;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    char* result = largestNumber(arr, n);
    printf("Largest number: %s\n", result);
    
    free(arr);
    free(result);
    return 0;
}
