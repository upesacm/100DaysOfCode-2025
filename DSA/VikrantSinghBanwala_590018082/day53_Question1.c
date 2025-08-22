#include <stdio.h>


int findMaxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;  
        }
    }

    return maxCount;
}

int main() {

    int arr1[] = {1, 1, 0, 1, 1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Max consecutive 1s (Example 1): %d\n", findMaxConsecutiveOnes(arr1, n1));  // ➜ 3

    
    int arr2[] = {1, 0, 1, 1, 0, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Max consecutive 1s (Example 2): %d\n", findMaxConsecutiveOnes(arr2, n2));  // ➜ 2

    return 0;
}