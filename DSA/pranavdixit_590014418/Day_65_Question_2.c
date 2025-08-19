#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)a)->second - ((Pair*)b)->second;
}

int maxChainLength(Pair arr[], int n) {
    qsort(arr, n, sizeof(Pair), cmp);

    int count = 1, lastEnd = arr[0].second;
    for (int i = 1; i < n; i++) {
        if (arr[i].first > lastEnd) {
            count++;
            lastEnd = arr[i].second;
        }
    }
    return count;
}

int main() {
    Pair arr1[] = {{5,24}, {15,25}, {27,40}, {50,60}};
    printf("Max chain length: %d\n", maxChainLength(arr1, 4)); // 3

    Pair arr2[] = {{1,2}, {2,3}, {3,4}};
    printf("Max chain length: %d\n", maxChainLength(arr2, 3)); // 2
    return 0;
}
