#include <stdio.h>
#include <stdlib.h>

int longestSubarrayWithSumK(int* arr, int n, int k) {
    int maxLength = 0;
    int currentSum = 0;
    int* hashMap = (int*)calloc(2 * n + 1, sizeof(int));
    for (int i = 0; i < 2 * n + 1; i++) {
        hashMap[i] = -1;
    }
    hashMap[n] = -1;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == k) {
            maxLength = i + 1;
        }

        if (hashMap[currentSum - k + n] != -1) {
            maxLength = (maxLength > i - hashMap[currentSum - k + n]) ? maxLength : (i - hashMap[currentSum - k + n]);
        }

        if (hashMap[currentSum + n] == -1) {
            hashMap[currentSum + n] = i;
        }
    }

    free(hashMap);
    return maxLength;
}

int main() {
    int arr1[] = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    printf("%d\n", longestSubarrayWithSumK(arr1, 6, k1));

    int arr2[] = {1, 2, 3};
    int k2 = 3;
    printf("%d\n", longestSubarrayWithSumK(arr2, 3, k2));

    return 0;
}
