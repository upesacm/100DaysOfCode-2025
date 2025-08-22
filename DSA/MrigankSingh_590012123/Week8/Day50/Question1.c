#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_Sum_Subarray(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        printf("Invalid window size\n");
        return INT_MIN;
    }
    
    if (n == 0) {
        printf("Empty array\n");
        return INT_MIN;
    }

    int maxSum = 0;
    for (int i = 0; i < k; i++) {
        maxSum += arr[i];
    }

    int currentSum = maxSum;
    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    int n, k;
  
    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    printf("Enter the window size (k): ");
    if (scanf("%d", &k) != 1) {
        printf("Invalid window size\n");
        free(arr);
        return 1;
    }

    int result = max_Sum_Subarray(arr, n, k);
    if (result != INT_MIN) {
        printf("Maximum sum of subarray of size %d: %d\n", k, result);
    }

    free(arr);
    return 0;
}
