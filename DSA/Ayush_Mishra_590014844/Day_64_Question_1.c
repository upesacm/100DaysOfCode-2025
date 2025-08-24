#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, end;
};

int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->end - ((struct Activity *)b)->end;
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];
    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    qsort(activities, n, sizeof(struct Activity), compare);

    int count = 1, last_end = activities[0].end;
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_end) {
            count++;
            last_end = activities[i].end;
        }
    }

    printf("Maximum number of non-overlapping activities: %d\n", count);
    return 0;
}
