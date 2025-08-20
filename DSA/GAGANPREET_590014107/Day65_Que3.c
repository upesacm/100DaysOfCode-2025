#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *interval1 = (Interval *)a;
    Interval *interval2 = (Interval *)b;
    return interval1->end - interval2->end;
}

int minRemovals(Interval intervals[], int n) {
    qsort(intervals, n, sizeof(Interval), compare);
    int count = 0;
    int lastEnd = intervals[0].end;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start < lastEnd) {
            count++;
        } else {
            lastEnd = intervals[i].end;
        }
    }
    return count;
}

int main() {
    Interval intervals1[] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result1 = minRemovals(intervals1, 4);
    printf("Remove %d → Remaining %d\n", result1, 4 - result1);

    Interval intervals2[] = {{1, 2}, {1, 2}, {1, 2}};
    int result2 = minRemovals(intervals2, 3);
    printf("Remove %d → Remaining %d\n", result2, 3 - result2);

    return 0;
}
