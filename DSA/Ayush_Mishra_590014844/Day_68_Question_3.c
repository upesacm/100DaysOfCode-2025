#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter number of negations (k): ");
    scanf("%d", &k);

    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n && k > 0; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
            k--;
        }
    }

    if (k % 2 == 1) {
        int min = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] < min) min = arr[i];
        for (int i = 0; i < n; i++)
            if (arr[i] == min) {
                arr[i] = -arr[i];
                break;
            }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    printf("Maximum sum after %d negations: %d\n", k, sum);
    return 0;
}
