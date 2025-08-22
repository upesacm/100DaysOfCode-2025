#include <stdio.h>

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int start = 0, end = 0, sum = 0, found = 0;

    while (end < n) {
        sum += arr[end];

        while (sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            printf("Subarray found from index %d to %d", start, end);
            found = 1;
            break;
        }

        end++;
    }

    if (!found) printf("No subarray with the given sum was found");

    return 0;
}
