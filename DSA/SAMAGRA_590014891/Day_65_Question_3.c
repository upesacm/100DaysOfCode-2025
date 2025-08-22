#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compareIntervals(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->end - i2->end;
}

int eraseOverlapIntervals(Interval intervals[], int n) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(Interval), compareIntervals);
    int count = 1, end = intervals[0].end;
    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= end) {
            count++;
            end = intervals[i].end;
        }
    }
    return n - count; 
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    Interval intervals[n];
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &intervals[i].start, &intervals[i].end);
    int removals = eraseOverlapIntervals(intervals, n);
    printf("Remove %d -> Remaining %d\n", removals, n - removals);
    return 0;
}
