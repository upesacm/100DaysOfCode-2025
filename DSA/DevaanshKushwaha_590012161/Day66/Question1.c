#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findPlatform(int arr[], int dep[], int n) {
    qsort(arr, n, sizeof(int), compare);
    qsort(dep, n, sizeof(int), compare);

    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            if (platforms > maxPlatforms) maxPlatforms = platforms;
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

int main() {
    int n;
    printf("Enter number of trains: ");
    scanf("%d", &n);

    int arr[n], dep[n];
    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter departure times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &dep[i]);

    printf("Minimum platforms needed = %d\n", findPlatform(arr, dep, n));

    return 0;
}
