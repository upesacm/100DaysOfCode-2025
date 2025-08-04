#include <stdio.h>
void findSubarrayWithGivenSum(int arr[], int n, int target) {
    int start = 0, current_sum = 0;
    for (int end = 0; end < n; end++) {
        current_sum += arr[end];
        while (current_sum > target && start <= end) {
            current_sum -= arr[start];
            start++;
        }
        if (current_sum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }
    }
    printf("No subarray found\n");
}
int main() {
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int target1 = 33;
    findSubarrayWithGivenSum(arr1, sizeof(arr1) / sizeof(arr1[0]), target1);
    int arr2[] = {1, 4, 0, 0, 3, 10, 5};
    int target2 = 7;
    findSubarrayWithGivenSum(arr2, sizeof(arr2) / sizeof(arr2[0]), target2);
    return 0;
}