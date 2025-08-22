#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n,k;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    int sums[n*(n+1)/2], idx=0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum += arr[j];
            sums[idx++] = sum;
        }
    }
    qsort(sums, idx, sizeof(int), cmp);
    printf("%d", sums[k-1]);
    return 0;
}
