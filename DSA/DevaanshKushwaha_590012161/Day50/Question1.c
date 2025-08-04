#include <stdio.h>

int main() {
    int arr[] = {100, 200, 300, 400};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = 0, window_sum = 0;

    for (int i = 0; i < k; i++) window_sum += arr[i];
    max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) max_sum = window_sum;
    }

    printf("%d", max_sum);
    return 0;
}
