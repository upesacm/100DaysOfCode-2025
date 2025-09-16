#include <stdio.h>

int maxSubarraySum(int* arr, int n) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < n; i++) {
        current_sum = arr[i] > current_sum + arr[i] ? arr[i] : current_sum + arr[i];
        max_sum = max_sum > current_sum ? max_sum : current_sum;
    }
    return max_sum;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubarraySum(arr, n);
    printf("Maximum subarray sum: %d\n", result);
    return 0;
}
