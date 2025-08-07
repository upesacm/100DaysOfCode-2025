#include <stdio.h>

int longestMountain(int arr[], int n) {
    int max_len = 0, i = 1;

    while (i < n - 1) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            while (left > 0 && arr[left - 1] < arr[left])
                left--;

            while (right < n - 1 && arr[right] > arr[right + 1])
                right++;

            int curr_len = right - left + 1;
            if (curr_len > max_len)
                max_len = curr_len;

            i = right;
        } else {
            i++;
        }
    }

    return max_len;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = longestMountain(arr, n);
    printf("Length of the longest mountain: %d\n", result);

    return 0;
}
