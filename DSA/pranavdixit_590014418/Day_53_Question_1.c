#include <stdio.h>

int findMaxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0, current = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            current++;
        else
            current = 0;

        if (current > maxCount)
            maxCount = current;
    }
    return maxCount;
}

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Max consecutive 1s: %d\n", findMaxConsecutiveOnes(arr, n)); // Output: 3
    return 0;
}
