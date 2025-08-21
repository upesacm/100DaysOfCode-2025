#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int compareMeetings(const void *a, const void *b) {
    return ((Meeting*)a)->end - ((Meeting*)b)->end;
}

int maxMeetings(int start[], int end[], int n) {
    Meeting meetings[n];
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int count = 0, last_end = -1;
    for (int i = 0; i < n; i++) {
        if (meetings[i].start > last_end) {
            count++;
            last_end = meetings[i].end;
        }
    }
    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};
    int n = 6;

    printf("Max meetings: %d\n", maxMeetings(start, end, n)); // 4
    return 0;
}

