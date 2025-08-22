#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->end - ((Interval*)b)->end;
}

int eraseOverlapIntervals(Interval arr[], int n) {
    if (n == 0) return 0;

    qsort(arr, n, sizeof(Interval), cmp);

    int count = 1, lastEnd = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }
    return n - count;
}

int main() {
    Interval arr1[] = {{1,2}, {2,3}, {3,4}, {1,3}};
    printf("Remove %d → Remaining %d\n", eraseOverlapIntervals(arr1, 4), 4 - eraseOverlapIntervals(arr1, 4)); 
    // Remove 1 → Remaining 3

    Interval arr2[] = {{1,2}, {1,2}, {1,2}};
    printf("Remove %d → Remaining %d\n", eraseOverlapIntervals(arr2, 3), 3 - eraseOverlapIntervals(arr2, 3)); 
    // Remove 2 → Remaining 1
    return 0;
}
