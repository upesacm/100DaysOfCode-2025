#include <stdio.h>

void subarrayWithGivenSum(int arr[], int n, int target) {
    int start = 0, currSum = 0;
    for (int end = 0; end < n; end++) {
        currSum += arr[end];

        
        while (currSum > target && start <= end) {
            currSum -= arr[start];
            start++;
        }

   
        if (currSum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }
    }
    printf("No subarray found with given sum.\n");
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int target = 33;
    int n = sizeof(arr) / sizeof(arr[0]);

    subarrayWithGivenSum(arr, n, target);
    return 0;
}

