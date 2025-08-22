#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) {
        printf("Invalid: Window size is larger than array length.\n");
        return -1;
    }

    // Compute sum of first window of size k
    int window_sum = 0;
    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    int max_sum = window_sum;

    // Slide the window from index k to end
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];  // Slide window
        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    return max_sum;
}

int main() {
    int arr1[] = {1, 4, 2, 10};
    int k1 = 2;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Max sum = %d\n", maxSumSubarray(arr1, n1, k1));  

    int arr2[] = {100, 200, 300, 400};
    int k2 = 2;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Max sum = %d\n", maxSumSubarray(arr2, n2, k2));  

    return 0;
}

