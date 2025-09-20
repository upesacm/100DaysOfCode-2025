#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Number of elements must be positive.\n");
        return 0;
    }

    int arr[n];
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int current_sum = arr[0];
    int max_sum = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > current_sum + arr[i]) {
            current_sum = arr[i];
        } else {
            current_sum = current_sum + arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("Maximum subarray sum is: %d\n", max_sum);
    return 0;
}
