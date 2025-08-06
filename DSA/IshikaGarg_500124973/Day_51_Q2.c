#include <stdio.h>
#define INF 1000000

int smallestSubarrayWithSum(int arr[], int n, int x) {
    int minLen = INF;
    int currSum = 0, left = 0;

    for (int right = 0; right < n; right++) {
        currSum += arr[right];

        while (currSum > x) {
            if (right - left + 1 < minLen)
                minLen = right - left + 1;

            currSum -= arr[left];
            left++;
        }
    }

    return (minLen == INF) ? 0 : minLen;
}

int main() {
    int arr1[] = {1, 4, 45, 6, 0, 19};
    printf("%d\n", smallestSubarrayWithSum(arr1, 6, 51)); // Output: 3

    int arr2[] = {1, 10, 5, 2, 7};
    printf("%d\n", smallestSubarrayWithSum(arr2, 5, 9));  // Output: 1

    return 0;
}

