#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // descending
}

int kthLargestSum(int arr[], int n, int k) {
    int size = n*(n+1)/2;
    int sums[size], idx = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            sums[idx++] = sum;
        }
    }
    qsort(sums, size, sizeof(int), compare);
    return sums[k-1];
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);

    printf("Kth largest subarray sum: %d\n", kthLargestSum(arr, n, k));
    return 0;
}
