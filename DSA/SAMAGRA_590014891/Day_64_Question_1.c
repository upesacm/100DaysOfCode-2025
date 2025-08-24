#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int cmp(const void *a, const void *b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

int activitySelection(int start[], int end[], int n) {
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
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], end[n];
    printf("Enter start times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &start[i]);
    printf("Enter end times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &end[i]);

    printf("Maximum activities: %d\n", activitySelection(start, end, n));
    return 0;
}
