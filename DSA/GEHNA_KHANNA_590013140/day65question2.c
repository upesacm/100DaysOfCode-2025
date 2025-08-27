#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)a)->second - ((Pair*)b)->second;
}

int main() {
    int n;
    scanf("%d", &n);
    Pair arr[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);

    qsort(arr, n, sizeof(Pair), cmp);
    int count = 1, lastEnd = arr[0].second;
    for (int i = 1; i < n; i++) {
        if (arr[i].first > lastEnd) {
            count++;
            lastEnd = arr[i].second;
        }
    }
    printf("%d\n", count);
    return 0;
}
