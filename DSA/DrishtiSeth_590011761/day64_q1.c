
#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, end;
};

int compare(const void* a, const void* b) {
    return ((struct Activity*)a)->end - ((struct Activity*)b)->end;
}

int maxActivities(int start[], int end[], int n) {
    struct Activity activities[n];
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }
    qsort(activities, n, sizeof(struct Activity), compare);
    int count = 1, lastEnd = activities[0].end;
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}

int main() {
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    printf("%d\n", maxActivities(start1, end1, n1));

    int start2[] = {1, 2, 3};
    int end2[] = {2, 3, 4};
    int n2 = sizeof(start2) / sizeof(start2[0]);
    printf("%d\n", maxActivities(start2, end2, n2));
    return 0;
}
