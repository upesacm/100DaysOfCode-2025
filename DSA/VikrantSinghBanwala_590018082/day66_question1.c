#include <stdio.h>

int findPlatform(int arr[], int dep[], int n) {
    int platforms_needed = 1, result = 1;
    int i = 1, j = 0;
    int arrival[n], departure[n];
    
    for (int k = 0; k < n; k++) {
        arrival[k] = arr[k];
        departure[k] = dep[k];
    }

    for (int k = 0; k < n - 1; k++) {
        for (int l = 0; l < n - k - 1; l++) {
            if (arrival[l] > arrival[l + 1]) {
                int temp = arrival[l];
                arrival[l] = arrival[l + 1];
                arrival[l + 1] = temp;
            }
            if (departure[l] > departure[l + 1]) {
                int temp = departure[l];
                departure[l] = departure[l + 1];
                departure[l + 1] = temp;
            }
        }
    }

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
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
    int arr1[] = {900, 940, 950, 1100, 1500, 1800};
    int dep1[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", findPlatform(arr1, dep1, n1));

    int arr2[] = {100, 200, 300};
    int dep2[] = {150, 250, 350};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", findPlatform(arr2, dep2, n2));

    return 0;
}
