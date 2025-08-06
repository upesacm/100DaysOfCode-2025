#include <stdio.h>

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += arr[i];
    max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) max_sum = window_sum;
    }

    printf("Maximum sum of subarray of size %d: %d", k, max_sum);
    return 0;
}
