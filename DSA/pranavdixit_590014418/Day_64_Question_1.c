#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int cmp(const void *a, const void *b) {
    return ((Activity *)a)->end - ((Activity *)b)->end;
}

int maxActivities(int start[], int end[], int n) {
    Activity arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].start = start[i];
        arr[i].end = end[i];
    }
    qsort(arr, n, sizeof(Activity), cmp);

    int count = 1, lastEnd = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }
    return count;
}

int main() {
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[]   = {2, 4, 6, 7, 9, 9};
    printf("Max activities: %d\n", maxActivities(start1, end1, 6)); // 4

    int start2[] = {1, 2, 3};
    int end2[]   = {2, 3, 4};
    printf("Max activities: %d\n", maxActivities(start2, end2, 3)); // 3
    return 0;
}
