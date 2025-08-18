#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int start, end;
} Activity;

int cmp(const void* a, const void* b) {
    Activity* x = (Activity*)a;
    Activity* y = (Activity*)b;
    return x->end - y->end;
}

int activitySelection(int start[], int end[], int n) {
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }


    qsort(activities, n, sizeof(Activity), cmp);

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
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    printf("%d\n", activitySelection(start, end, n)); 
    return 0;
}

