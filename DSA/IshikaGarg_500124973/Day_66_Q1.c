#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minPlatforms(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), cmp);
    qsort(dep, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int platforms = 0, max_platforms = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++; // train arrives
            if (platforms > max_platforms)
                max_platforms = platforms;
            i++;
        } else {
            platforms--; // train departs
            j++;
        }
    }
    return max_platforms;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", minPlatforms(arr, dep, n)); // Output: 3
    return 0;
}

