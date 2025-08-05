#include <stdio.h>
#include <limits.h>

int smallestSubarrayWithSum(int arr[], int n, int x) {
    int minLen = n + 1, start = 0, end = 0, sum = 0;

    while (end < n) {
        while (sum <= x && end < n)
            sum += arr[end++];

        while (sum > x && start < n) {
            if (end - start < minLen)
                minLen = end - start;
            sum -= arr[start++];
        }
    }

    return (minLen == n + 1) ? 0 : minLen;
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &x);
    printf("%d\n", smallestSubarrayWithSum(arr, n, x));
    return 0;
}
