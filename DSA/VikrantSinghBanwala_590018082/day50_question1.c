#include<stdio.h>
int maxSumSubarray(int arr[], int n, int k) {
    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }
    return max_sum;
}
int main() {
    int arr1[] = {1, 4, 2, 10};
    int k1 = 2;
    printf("%d\n", maxSumSubarray(arr1, sizeof(arr1) / sizeof(arr1[0]), k1));
    int arr2[] = {100, 200, 300, 400};
    int k2 = 2;
    printf("%d\n", maxSumSubarray(arr2, sizeof(arr2) / sizeof(arr2[0]), k2));
    return 0;
}