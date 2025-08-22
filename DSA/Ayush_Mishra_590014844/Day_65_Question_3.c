#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->end - ((Interval *)b)->end;
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Interval tasks[n];
    printf("Enter tasks (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tasks[i].start, &tasks[i].end);
    }

    qsort(tasks, n, sizeof(Interval), compare);

    int count = 1;
    int last_end = tasks[0].end;

    for (int i = 1; i < n; i++) {
        if (tasks[i].start >= last_end) {
            count++;
            last_end = tasks[i].end;
        }
    }

    printf("Minimum tasks to remove: %d\n", n - count);
    printf("Remaining non-overlapping tasks: %d\n", count);
    return 0;
}
