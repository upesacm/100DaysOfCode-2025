#include <stdio.h>

int smallestSubarray(int arr[], int n, int x) {
    int minLen = n + 1, sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];
        while (sum > x) {
            if (right - left + 1 < minLen)
                minLen = right - left + 1;
            sum -= arr[left];
            left++;
        }
    }
    if (minLen == n + 1)
        return 0;
    return minLen;
}

int main() {
    int n, x, arr[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &x);
    printf("%d\n", smallestSubarray(arr, n, x));
    return 0;
}
