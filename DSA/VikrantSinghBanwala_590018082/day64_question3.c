#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;
    return job2->profit - job1->profit;
}

void jobScheduling(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(jobs[0]), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        slots[i] = -1;
    }

    int totalProfit = 0;
    int jobCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    printf("%d jobs, Profit: %d\n", jobCount, totalProfit);
}

int main() {
    struct Job jobs1[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n1 = sizeof(jobs1) / sizeof(jobs1[0]);

    struct Job jobs2[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}};
    int n2 = sizeof(jobs2) / sizeof(jobs2[0]);

    jobScheduling(jobs1, n1);
    jobScheduling(jobs2, n2);

    return 0;
}
