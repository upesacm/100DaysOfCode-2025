#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int start, end;
} Meeting;

int compare(const void *a, const void *b) {
    return ((Meeting*)a)->end - ((Meeting*)b)->end;
}

int maxMeetings(int start[], int end[], int n) {
    Meeting meetings[n];
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    qsort(meetings, n, sizeof(Meeting), compare);

    int count = 1;
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start > lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }
    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    printf("Maximum Non-overlapping Meetings = %d\n", maxMeetings(start, end, n));
    return 0;
}

