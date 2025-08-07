#include <stdio.h>

int longestMountain(int* arr, int arrSize) {
    int maxLen = 0;

    for (int i = 1; i < arrSize - 1; i++) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            while (left > 0 && arr[left - 1] < arr[left]) left--;
            while (right < arrSize - 1 && arr[right] > arr[right + 1]) right++;

            int currentLen = right - left + 1;
            if (currentLen > maxLen) maxLen = currentLen;
            i = right;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {2, 1, 4, 7, 3, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Longest Mountain Length: %d\n", longestMountain(arr, size));
    return 0;
}

