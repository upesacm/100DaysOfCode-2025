#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    for (int i = 0; i < n && k > 0; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
            k--;
        }
    }

    // If still odd flips left
    qsort(arr, n, sizeof(int), cmp);
    if (k % 2 == 1) arr[0] = -arr[0];

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    printf("%d\n", sum);
    return 0;
}
