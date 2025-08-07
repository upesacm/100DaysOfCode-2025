#include <stdio.h>
#include <limits.h>

int smallest_Subarray_Sum(int arr[], int n, int x) {
    int currentSum = 0;
    int minLength = INT_MAX;
    int start = 0;

    for (int end = 0; end < n; end++) {
        currentSum += arr[end];

        while (currentSum > x && start <= end) {
            int currentLength = end - start + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            currentSum -= arr[start];
            start++;
        }
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}

int main() {
    int n, x;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum (x): ");
    scanf("%d", &x);

    int result = smallest_Subarray_Sum(arr, n, x);

    if (result == -1) {
        printf("No subarray found with sum greater than %d\n", x);
    } else {
        printf("Smallest subarray length with sum > %d: %d\n", x, result);
    }

    return 0;
}
