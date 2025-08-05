#include <stdio.h>

int smallestSubarray(int arr[], int n, int x) {
    int start = 0, end = 0, sum = 0, minLen = n + 1;
    while (end < n) {
        while (sum <= x && end < n) sum += arr[end++];
        while (sum > x && start < n) {
            if (end - start < minLen) minLen = end - start;
            sum -= arr[start++];
        }
    }
    if (minLen == n + 1) return 0;
    return minLen;
}

int main() {
    int n, x, arr[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &x);
    printf("%d\n", smallestSubarray(arr, n, x));
    return 0;
}
