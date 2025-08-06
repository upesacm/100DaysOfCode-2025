#include <stdio.h>
#include <limits.h>

int smallestSubWithSum(int arr[], int n, int x) {
    int start = 0, end = 0, curr_sum = 0, min_len = INT_MAX;

    while (end < n) {
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];

        while (curr_sum > x && start < n) {
            if (end - start < min_len)
                min_len = end - start;

            curr_sum -= arr[start++];
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}

int main() {
    int arr[1000], n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of x: ");
    scanf("%d", &x);

    int result = smallestSubWithSum(arr, n, x);
    if (result)
        printf("Smallest subarray length with sum > %d: %d\n", x, result);
    else
        printf("No subarray found with sum > %d\n", x);

    return 0;
}
