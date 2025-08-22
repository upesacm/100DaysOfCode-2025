#include <stdio.h>

int maxSumSubarrayK(int arr[], int n, int k) {
    if (n < k) return -1;

    int max_sum = 0, window_sum = 0;

    for (int i = 0; i < k; i++)
        window_sum += arr[i];
    
    max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    return max_sum;
}

int main() {
    int arr1[] = {1, 4, 2, 10};
    int arr2[] = {100, 200, 300, 400};
    printf("Max sum: %d\n", maxSumSubarrayK(arr1, 4, 2));  
    printf("Max sum: %d\n", maxSumSubarrayK(arr2, 4, 2));  
    return 0;
}
