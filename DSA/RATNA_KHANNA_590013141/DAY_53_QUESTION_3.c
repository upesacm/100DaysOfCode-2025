#include <stdio.h>

int main() {
    int n;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_len = 0, i = 1;
    while(i < n - 1) {
        if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;
            while(left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }
            while(right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }
            int len = right - left + 1;
            if(len > max_len) {
                max_len = len;
            }
            i = right;
        } else {
            i++;
        }
    }

    printf("output-%d\n", max_len);
    return 0;
}
