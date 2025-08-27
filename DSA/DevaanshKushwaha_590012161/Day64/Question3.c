#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

// Comparator: sort by profit in descending order
int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) slots[i] = -1;

    int countJobs = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("%d jobs, Profit: %d\n", countJobs, totalProfit);
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter job details (id deadline profit):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobScheduling(jobs, n);
    return 0;
}
