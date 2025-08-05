#include <stdio.h>
#include <limits.h>

int smallestSubWithSum(int arr[], int n, int x) {
    int minLen = n + 1;
    int sum = 0, start = 0, end = 0;

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
    int arr[] = {1, 4, 45, 6, 0, 19};
    int x = 51;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = smallestSubWithSum(arr, n, x);
    printf("%d\n", result); 

    return 0;
}
