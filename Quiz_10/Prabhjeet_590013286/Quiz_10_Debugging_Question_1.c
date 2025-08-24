#include <stdio.h>
#include <stdlib.h>

// Each task has a start and end time
struct Task {
    int start;
    int end;
};

// Sort tasks by when they finish (earliest first)
int sortByEndTime(const void* a, const void* b) {
    return ((struct Task*)a)->end - ((struct Task*)b)->end;
}

// Function to choose the most tasks without overlap
int pickMaxTasks(int start[], int end[], int n) {
    struct Task tasks[n];

    // Fill task list
    for (int i = 0; i < n; i++) {
        tasks[i].start = start[i];
        tasks[i].end = end[i];
    }

    // Sort tasks by end time (greedy strategy)
    qsort(tasks, n, sizeof(struct Task), sortByEndTime);

    int count = 1;  // First task is always picked
    int lastEnd = tasks[0].end;

    // Go through the rest and pick if they don’t overlap
    for (int i = 1; i < n; i++) {
        if (tasks[i].start >= lastEnd) {
            count++;
            lastEnd = tasks[i].end;
        }
    }

    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    int result = pickMaxTasks(start, end, n);
    printf("You can do %d tasks without overlap.\n", result);  // Output: 4

    return 0;
}
