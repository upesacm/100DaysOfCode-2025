#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int cmp(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), cmp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;

    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) slot[i] = -1;

    int jobCount = 0, totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                jobCount++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("%d jobs, Profit: %d\n", jobCount, totalProfit);
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter jobs (id deadline profit):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

    jobScheduling(jobs, n);
    return 0;
}
