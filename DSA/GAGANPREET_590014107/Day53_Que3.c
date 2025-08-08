#include <stdio.h>

int longestMountain(int* arr, int arrSize) {
    int maxLen = 0;
    int i = 1;

    while (i < arrSize - 1) {
        
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

        
            while (right < arrSize - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }

        
            i = right;
        } else {
            i++;
        }
    }

    return maxLen;
}

int main() {

    int arr1[] = {2, 1, 4, 7, 3, 2, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Longest mountain (Example 1): %d\n", longestMountain(arr1, size1));  // ➜ 5

    
    int arr2[] = {2, 2, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Longest mountain (Example 2): %d\n", longestMountain(arr2, size2));  // ➜ 0

    return 0;
}
#include <stdio.h>

int longestMountain(int* arr, int arrSize) {
    int maxLen = 0;
    int i = 1;

    while (i < arrSize - 1) {
        
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

        
            while (right < arrSize - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }

        
            i = right;
        } else {
            i++;
        }
    }

    return maxLen;
}

int main() {

    int arr1[] = {2, 1, 4, 7, 3, 2, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Longest mountain (Example 1): %d\n", longestMountain(arr1, size1));  // ➜ 5

    
    int arr2[] = {2, 2, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Longest mountain (Example 2): %d\n", longestMountain(arr2, size2));  // ➜ 0

    return 0;
}
