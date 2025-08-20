#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], dep[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) scanf("%d", &dep[i]);

    qsort(arr, n, sizeof(int), compare);
    qsort(dep, n, sizeof(int), compare);

    int platforms = 1, max_platforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        if (platforms > max_platforms) max_platforms = platforms;
    }

    printf("%d\n", max_platforms);
    return 0;
}
