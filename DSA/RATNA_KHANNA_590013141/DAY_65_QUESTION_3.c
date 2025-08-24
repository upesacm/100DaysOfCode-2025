#include <stdio.h>

struct Interval {
    int start, end;
};

// Sort by end time
void sortIntervals(struct Interval arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i].end > arr[j].end) {
                struct Interval temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Interval intervals[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    printf("Input:\nintervals = [");
    for(int i = 0; i < n; i++) {
        printf("(%d, %d)", intervals[i].start, intervals[i].end);
        if(i != n-1) printf(", ");
    }
    printf("]\n");

    sortIntervals(intervals, n);

    int count = 1; 
    int last_end = intervals[0].end;

    for(int i = 1; i < n; i++) {
        if(intervals[i].start >= last_end) {
            count++;
            last_end = intervals[i].end;
        }
    }

    int toRemove = n - count;
    printf("Output:\nRemove %d → Remaining %d\n", toRemove, count);

    return 0;
}
