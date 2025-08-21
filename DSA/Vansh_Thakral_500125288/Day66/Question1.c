#include <stdio.h>
#include <stdlib.h>


int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findMinPlatforms(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), cmpfunc);
    qsort(dep, n, sizeof(int), cmpfunc);

    int platforms = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        if (platforms > result)
            result = platforms;
    }
    return result;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum Platforms Required = %d\n", findMinPlatforms(arr, dep, n));
    return 0;
}
