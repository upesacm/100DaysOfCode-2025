#include <stdio.h>
#include <stdbool.h>

// Function to check if a pair exists in a sorted array that sums to the target
bool hasPairWithSum(int arr[], int n, int target) {
    // ✅ Task 1: Fix the off-by-one error
    // Original: int right = n; → wrong because arr[n] is out of bounds
    int left = 0;
    int right = n - 1;  // ✅ Fix: right should be n - 1 (last valid index)

    // ✅ Task 2: Use left < right (not <=) to avoid duplicate or same element usage
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        } else if (sum < target) {
            left++;  // Move to a larger number
        } else {
            right--;  // Move to a smaller number
        }
    }

    return false;
}

int main() {
    // ✅ Task 3: Fix all syntax issues in main
    int arr[] = {1, 2, 4, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    if (hasPairWithSum(arr, n, target)) {
        printf("Pair exists\n");
    } else {
        printf("No such pair\n");
    }

    return 0;
}
