#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int target) {
    int start = 0, currSum = 0;

    for (int end = 0; end < n; end++) {
        currSum += arr[end];

        while (currSum > target && start <= end)
            currSum -= arr[start++];

        if (currSum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }
    }

    printf("No subarray with given sum found\n");
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int target = 33;
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubarrayWithSum(arr, n, target);
    return 0;
}
