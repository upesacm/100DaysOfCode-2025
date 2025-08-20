#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findMinPlatforms(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), cmp);
    qsort(dep, n, sizeof(int), cmp);
    int plat_needed = 0, result = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            if (plat_needed > result)
                result = plat_needed;
            i++;
        } else {
            plat_needed--;
            j++;
        }
    }
    return result;
}

int main() {
    int n;
    printf("Enter number of trains: ");
    scanf("%d", &n);
    int arr[n], dep[n];
    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter departure times: ");
    for (int i = 0; i < n; i++) scanf("%d", &dep[i]);
    printf("Minimum platforms needed: %d\n", findMinPlatforms(arr, dep, n));
    return 0;
}
