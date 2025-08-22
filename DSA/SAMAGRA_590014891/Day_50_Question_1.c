#include <stdio.h>

int maxSumSubarray(int arr[], int n, int k) {
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
    int arr[] = {100, 200, 300, 400};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxSumSubarray(arr, n, k));
    return 0;
}
