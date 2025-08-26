#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void* a, const void* b) {
    return ((Interval*)a)->end - ((Interval*)b)->end;
}

int minTasksToRemove(Interval intervals[], int n) {
    qsort(intervals, n, sizeof(Interval), compare);
    
    int count = 0;
    int lastEnd = -1;
    
    for (int i = 0; i < n; i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }
    
    return n - count;
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    
    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    
    printf("Enter task intervals (start end): \n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: ", i + 1);
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    
    int removeCount = minTasksToRemove(intervals, n);
    printf("Tasks to remove: %d\n", removeCount);
    printf("Tasks remaining: %d\n", n - removeCount);
    
    free(intervals);
    return 0;
}
