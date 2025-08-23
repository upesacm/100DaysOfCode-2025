#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxSumAfterKNegations(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n && k > 0; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
            k--;
        }
    }
    qsort(arr, n, sizeof(int), cmp);
    if (k % 2 == 1) arr[0] = -arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter number of operations: ");
    scanf("%d", &k);
    int result = maxSumAfterKNegations(arr, n, k);
    printf("Maximum sum after %d negations: %d\n", k, result);
    return 0;
}
