#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int maxLen = 0, i = 1;
    while (i < n - 1) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int left = i, right = i;
            while (left > 0 && arr[left] > arr[left - 1]) left--;
            while (right < n - 1 && arr[right] > arr[right + 1]) right++;
            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
            i = right;
        } else i++;
    }
    printf("Length of longest mountain: %d", maxLen);
}
