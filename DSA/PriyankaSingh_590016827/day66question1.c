#include <stdio.h>
#include <stdlib.h>

// Minimum Platforms at Railway Station
int findMinPlatforms(int arr[], int dep[], int n) {
    int i = 1, j = 0;
    int platforms_needed = 1;
    int result = 1;

    // Sort both arrival and departure arrays
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (arr[b] > arr[b + 1]) {
                int temp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = temp;
                temp = dep[b];
                dep[b] = dep[b + 1];
                dep[b + 1] = temp;
            }
        }
    }

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms_needed++;
            i++;
        } else {
            platforms_needed--;
            j++;
        }
        if (platforms_needed > result) {
            result = platforms_needed;
        }
    }
    return result;
}

int main() {
    // Example 1
    int arr1[] = {900, 940, 950, 1100, 1500, 1800};
    int dep1[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Minimum Platforms needed: %d\n", findMinPlatforms(arr1, dep1, n1));

    // Example 2
    int arr2[] = {100, 200, 300};
    int dep2[] = {150, 250, 350};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Minimum Platforms needed: %d\n", findMinPlatforms(arr2, dep2, n2));

    return 0;
}
