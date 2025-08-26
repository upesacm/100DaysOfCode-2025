#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compare(const void* a, const void* b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

int maxActivities(int start[], int end[], int n) {
    Activity* activities = (Activity*)malloc(n * sizeof(Activity));
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }
    
    qsort(activities, n, sizeof(Activity), compare);
    
    int count = 0;
    int lastEnd = -1;
    
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    
    free(activities);
    return count;
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    
    int* start = (int*)malloc(n * sizeof(int));
    int* end = (int*)malloc(n * sizeof(int));
    
    printf("Enter start times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }
    
    printf("Enter end times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }
    
    printf("Maximum non-overlapping activities: %d\n", maxActivities(start, end, n));
    
    free(start);
    free(end);
    return 0;
}
