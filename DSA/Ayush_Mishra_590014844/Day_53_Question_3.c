#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxLen = 0;
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            while(left > 0 && arr[left] > arr[left - 1])
                left--;
            while(right < n - 1 && arr[right] > arr[right + 1])
                right++;

            int len = right - left + 1;
            if(len > maxLen)
                maxLen = len;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}
