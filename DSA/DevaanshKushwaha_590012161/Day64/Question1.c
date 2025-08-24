#include <stdio.h>
#include <stdlib.h>

// Structure for activity
typedef struct {
    int start, end;
} Activity;

// Comparator for qsort: sort by end time
int compare(const void *a, const void *b) {
    Activity *act1 = (Activity *)a;
    Activity *act2 = (Activity *)b;
    return act1->end - act2->end;
}

// Function to select maximum number of activities
int maxActivities(int start[], int end[], int n) {
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    qsort(activities, n, sizeof(Activity), compare);

    int count = 1;  
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], end[n];
    printf("Enter start times: ");
    for (int i = 0; i < n; i++) scanf("%d", &start[i]);

    printf("Enter end times: ");
    for (int i = 0; i < n; i++) scanf("%d", &end[i]);

    int result = maxActivities(start, end, n);
    printf("Maximum activities = %d\n", result);

    return 0;
}
