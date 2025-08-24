#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id, deadline, profit;
};

// Sort jobs by profit (descending)
int cmp(const void *a, const void *b) {
    struct Job *x = (struct Job*)a;
    struct Job *y = (struct Job*)b;
    return y->profit - x->profit;
}

int jobScheduling(struct Job jobs[], int n) {
    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Create slot array to keep track of free time slots
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;  // -1 means free

    int count = 0, totalProfit = 0;

    // Iterate through jobs in order of profit
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job before its deadline
        for (int d = jobs[i].deadline; d > 0; d--) {
            if (slot[d] == -1) {
                slot[d] = jobs[i].id;  // assign job to slot
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("%d jobs, Profit = %d\n", count, totalProfit);
    return totalProfit;
}

int main() {
    // Example 1
    struct Job jobs1[] = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
    int n1 = sizeof(jobs1) / sizeof(jobs1[0]);
    qsort(jobs1, n1, sizeof(struct Job), cmp);
    jobScheduling(jobs1, n1);  // Expected: 2 jobs, Profit = 60

    // Example 2
    struct Job jobs2[] = {{1,2,100}, {2,1,19}, {3,2,27}};
    int n2 = sizeof(jobs2) / sizeof(jobs2[0]);
    qsort(jobs2, n2, sizeof(struct Job), cmp);
    jobScheduling(jobs2, n2);  // Expected: 2 jobs, Profit = 127

    return 0;
}

