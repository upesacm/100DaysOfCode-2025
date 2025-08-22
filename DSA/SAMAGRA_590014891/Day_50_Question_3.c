#include <stdio.h>

void subarrayWithGivenSum(int arr[], int n, int target) {
    int start = 0, end = 0, curr_sum = 0;

    while (end < n) {
        curr_sum += arr[end];

        while (curr_sum > target && start < end)
            curr_sum -= arr[start++];

        if (curr_sum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }

        end++;
    }

    printf("No subarray with given sum found\n");
}

int main() {
    int arr[] = {1, 4, 0, 0, 3, 10, 5};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    subarrayWithGivenSum(arr, n, target);
    return 0;
}
