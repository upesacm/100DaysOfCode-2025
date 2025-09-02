#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void* a, const void* b) {
    return ((Meeting*)a)->end - ((Meeting*)b)->end;
}

int maxMeetings(int start[], int end[], int n) {
    Meeting* meetings = (Meeting*)malloc(n * sizeof(Meeting));
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }
    
    qsort(meetings, n, sizeof(Meeting), compare);
    
    int count = 0;
    int lastEnd = -1;
    
    for (int i = 0; i < n; i++) {
        if (meetings[i].start >= lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }
    
    free(meetings);
    return count;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
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
    
    int result = maxMeetings(start, end, n);
    printf("Maximum non-overlapping meetings: %d\n", result);
    
    free(start);
    free(end);
    return 0;
}
