#include <stdio.h>
#include <limits.h>

int smallestSubarraySum(int arr[], int n, int x) {
    int minLen = INT_MAX;
    int sum = 0, left = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > x) {
            int len = right - left + 1;
            if (len < minLen) minLen = len;
            sum -= arr[left++];
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    int arr1[] = {1, 4, 45, 6, 0, 19};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int x1 = 51;
    printf("%d\n", smallestSubarraySum(arr1, n1, x1)); 

    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int x2 = 9;
    printf("%d\n", smallestSubarraySum(arr2, n2, x2)); 

    return 0;
}

