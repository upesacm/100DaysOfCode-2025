#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

// Comparison function to sort by end time
int compareIntervals(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->end - i2->end;
}

int eraseOverlap(struct Interval intervals[], int n) {
    qsort(intervals, n, sizeof(struct Interval), compareIntervals);

    int count = 1;  // Keep first interval
    int lastEnd = intervals[0].end;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }

    return n - count;  // Minimum removals
}

int main() {
    struct Interval intervals1[] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int n1 = sizeof(intervals1) / sizeof(intervals1[0]);
    printf("Remove %d → Remaining %d\n", eraseOverlap(intervals1, n1), n1 - eraseOverlap(intervals1, n1));

    struct Interval intervals2[] = {{1, 2}, {1, 2}, {1, 2}};
    int n2 = sizeof(intervals2) / sizeof(intervals2[0]);
    printf("Remove %d → Remaining %d\n", eraseOverlap(intervals2, n2), n2 - eraseOverlap(intervals2, n2));

    return 0;
}

