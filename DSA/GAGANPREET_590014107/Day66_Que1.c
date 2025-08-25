#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


int findMinPlatforms(int arr[], int dep[], int n) {
    
    qsort(arr, n, sizeof(int), compare);
    qsort(dep, n, sizeof(int), compare);

    int platforms = 1;     
    int maxPlatforms = 1;  
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;  
            i++;
        } else {
            platforms--;  
            j++;
        }
        if (platforms > maxPlatforms)
            maxPlatforms = platforms;
    }

    return maxPlatforms;
}

int main() {
    
    int arr1[] = {900, 940, 950, 1100, 1500, 1800};
    int dep1[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Minimum platforms needed (Example 1): %d\n", findMinPlatforms(arr1, dep1, n1));  // ➜ 3

    
    int arr2[] = {100, 200, 300};
    int dep2[] = {150, 250, 350};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Minimum platforms needed (Example 2): %d\n", findMinPlatforms(arr2, dep2, n2));  // ➜ 1

    return 0;
}
