#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int compare(const void *a, const void *b) {
    return ((Activity *)a)->end - ((Activity *)b)->end;
}

int maxActivities(Activity arr[], int n) {
    qsort(arr, n, sizeof(Activity), compare);

    int count = 1;
    int lastEnd = arr[0].end;
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
    Activity arr[n];
    printf("Enter start times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].start);
    printf("Enter end times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].end);

    printf("Maximum activities: %d\n", maxActivities(arr, n));
    return 0;
}
