#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;


int cmp(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->end - y->end;
}

int eraseOverlapIntervals(Interval intervals[], int n) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(Interval), cmp);

    int count = 1; 
    int lastEnd = intervals[0].end;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }

    return n - count; 
}

int main() {
    Interval intervals[] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int removals = eraseOverlapIntervals(intervals, n);
    printf("Remove %d → Remaining %d\n", removals, n - removals); 
    return 0;
}

