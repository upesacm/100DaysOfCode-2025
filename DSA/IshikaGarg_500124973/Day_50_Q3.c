#include <stdio.h>

void subarrayWithGivenSum(int arr[], int n, int target) {
    int start = 0, end = 0, curr_sum = 0;

    while (end < n) {
        curr_sum += arr[end];

        // Shrink window if current sum exceeds target
        while (curr_sum > target && start < end) {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }

        end++;
    }

    printf("No subarray found\n");
}

int main() {
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    subarrayWithGivenSum(arr1, n1, 33); 

    int arr2[] = {1, 4, 0, 0, 3, 10, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    subarrayWithGivenSum(arr2, n2, 7);   

    return 0;
}

