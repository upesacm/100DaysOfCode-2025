#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval*)a)->end - ((Interval*)b)->end;
}

int eraseOverlapIntervals(Interval intervals[], int n) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(Interval), compare);

    int count = 1;
    int lastEnd = intervals[0].end;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }
    return n - count; // tasks to remove
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n];
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &intervals[i].start, &intervals[i].end);

    int toRemove = eraseOverlapIntervals(intervals, n);
    printf("Remove %d -> Remaining %d\n", toRemove, n - toRemove);

    return 0;
}
