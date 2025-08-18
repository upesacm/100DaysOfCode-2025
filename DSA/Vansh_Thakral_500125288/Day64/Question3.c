#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;


int cmp(const void* a, const void* b) {
    Job* x = (Job*)a;
    Job* y = (Job*)b;
    return y->profit - x->profit;
}

int jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), cmp);

    // Find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int count = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("%d jobs, Profit: %d\n", count, totalProfit);
    return totalProfit;
}

int main() {
    Job jobs[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);
    return 0;
}

