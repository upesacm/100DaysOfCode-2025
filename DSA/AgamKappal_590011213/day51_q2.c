#include <stdio.h>
#include <limits.h>

int smallestSubarray(int arr[], int n, int x) {
    int minLen = n + 1, start = 0, sum = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];

        while (sum > x) {
            if (end - start + 1 < minLen)
                minLen = end - start + 1;
            sum -= arr[start++];
        }
    }

    return (minLen == n + 1) ? 0 : minLen;
}

int main() {
    int arr1[] = {1, 4, 45, 6, 0, 19};
    int x1 = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Output: %d\n", smallestSubarray(arr1, n1, x1)); // Output: 3

    int arr2[] = {1, 10, 5, 2, 7};
    int x2 = 9;
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Output: %d\n", smallestSubarray(arr2, n2, x2)); // Output: 1

    return 0;
}
