#include <stdio.h>

int longestMountain(int arr[], int n) {
    int maxLen = 0, i = 1;

    while (i < n - 1) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            while (left > 0 && arr[left - 1] < arr[left])
                left--;

            int right = i + 1;
            while (right < n - 1 && arr[right] > arr[right + 1])
                right++;

            int len = right - left + 1;
            if (len > maxLen)
                maxLen = len;

            i = right;
        } else {
            i++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {2, 1, 4, 7, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Longest mountain length: %d\n", longestMountain(arr, n)); // Output: 5
    return 0;
}
