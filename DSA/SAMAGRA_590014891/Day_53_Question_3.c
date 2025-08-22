#include <stdio.h>

int longestMountain(int* arr, int arrSize) {
    int maxLen = 0, i = 1;

    while (i < arrSize - 1) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            while (left > 0 && arr[left - 1] < arr[left])
                left--;
            while (right < arrSize - 1 && arr[right] > arr[right + 1])
                right++;

            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
            i = right;
        } else {
            i++;
        }
    }

    return maxLen;
}
