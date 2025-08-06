#include <stdio.h>
#include <stdlib.h>

void find_Subarray(int arr[], int n, int target) {
    int currentSum = 0;
    int start = 0;
    int found = 0;
    
    for (int end = 0; end < n; end++) {
        currentSum += arr[end];
        
        while (currentSum > target && start <= end) {
            currentSum -= arr[start];
            start++;
        }
        
        if (currentSum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No subarray found with sum %d\n", target);
    }
}

int* getArray(int* size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);
    
    if (*size <= 0) {
        printf("Invalid array size\n");
        return NULL;
    }
    
    int* arr = (int*)malloc(*size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    printf("Enter %d non-negative integers: ", *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1 || arr[i] < 0) {
            printf("Invalid input. Only non-negative integers allowed.\n");
            free(arr);
            return NULL;
        }
    }
    
    return arr;
}

int main() {
    int n, target;
    int* arr = getArray(&n);
    
    if (!arr) {
        return 1;
    }
    
    printf("Enter the target sum: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target sum\n");
        free(arr);
        return 1;
    }
    
    find_Subarray(arr, n, target);
    free(arr);
    return 0;
}
