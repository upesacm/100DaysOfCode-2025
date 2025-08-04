#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int target) {
    int start = 0, end = 0;
    int currentSum = 0;

    while (end < n) {
    
        currentSum += arr[end];

    
        while (currentSum > target && start < end) {
            currentSum -= arr[start];
            start++;
        }

    
        if (currentSum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }

    
        end++;
    }

    printf("No subarray with given sum found\n");
}

int main() {
    
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 33;
    findSubarrayWithSum(arr1, n1, target1);  


    int arr2[] = {1, 4, 0, 0, 3, 10, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 7;
    findSubarrayWithSum(arr2, n2, target2); 

    return 0;
}
