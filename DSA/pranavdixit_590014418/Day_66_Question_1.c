#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int*)a - *(int*)b); }

int findMinPlatforms(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), cmp);
    qsort(dep, n, sizeof(int), cmp);

    int i = 0, j = 0, plat = 0, maxPlat = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) { 
            plat++; 
            if (plat > maxPlat) maxPlat = plat;
            i++;
        } else {
            plat--;
            j++;
        }
    }
    return maxPlat;
}

int main() {
    int arr1[] = {900, 940, 950, 1100, 1500, 1800};
    int dep1[] = {910, 1200, 1120, 1130, 1900, 2000};
    printf("Minimum platforms: %d\n", findMinPlatforms(arr1, dep1, 6)); // 3

    int arr2[] = {100, 200, 300};
    int dep2[] = {150, 250, 350};
    printf("Minimum platforms: %d\n", findMinPlatforms(arr2, dep2, 3)); // 1
    return 0;
}
