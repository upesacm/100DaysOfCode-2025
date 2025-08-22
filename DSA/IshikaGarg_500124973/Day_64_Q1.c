#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, end;
};

// Comparator for qsort: sort activities by end time
int cmp(const void *a, const void *b) {
    struct Activity *x = (struct Activity*)a;
    struct Activity *y = (struct Activity*)b;
    return x->end - y->end;
}

int activitySelection(int start[], int end[], int n) {
    struct Activity acts[n];
    for (int i = 0; i < n; i++) {
        acts[i].start = start[i];
        acts[i].end = end[i];
    }

    // Sort by end time
    qsort(acts, n, sizeof(struct Activity), cmp);

    // First activity is always selected
    int count = 1;
    int lastEnd = acts[0].end;

    for (int i = 1; i < n; i++) {
        if (acts[i].start >= lastEnd) {
            count++;
            lastEnd = acts[i].end;
        }
    }
    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    printf("Maximum activities = %d\n", activitySelection(start, end, n));
    return 0;
}

